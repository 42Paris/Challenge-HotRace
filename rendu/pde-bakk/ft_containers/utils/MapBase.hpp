/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MapBase.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 23:49:18 by peerdb        #+#    #+#                 */
/*   Updated: 2020/11/04 16:47:23 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPBASE_HPP
# define MAPBASE_HPP

# include <memory>
# include <iostream>
# include <cstddef>
# include "MapNode.hpp"
# include "../Iterators/MapIterator.hpp"
# include "../Iterators/ReverseIterator.hpp"
# include "Pair.hpp"
# include "Traits.hpp"
# include "Extra.hpp"
# include "Colours.h"

namespace ft {

template < class Key, class Value, class NodeContents, class Compare = less<Key>, class Alloc = std::allocator<ft::pair<const Key,Value> > >
	class MapBase {
	public:
		typedef Key							key_type;
		typedef Value						mapped_type;
		typedef NodeContents				value_type;
		typedef	Compare						key_compare;
		typedef Alloc						allocator_type;
		typedef	value_type&					reference;
		typedef	const value_type&			const_reference;
		typedef	value_type*					pointer;
		typedef	const value_type*			const_pointer;
		typedef	ptrdiff_t					difference_type;
		typedef	size_t						size_type;
		typedef node<value_type, key_compare>	mapnode;
		typedef MapIterator<value_type, pointer, reference, Compare >				iterator;
		typedef MapIterator<value_type, const_pointer, const_reference, Compare >	const_iterator;
		typedef ReverseBI<iterator>													reverse_iterator;
		typedef ReverseBI<const_iterator>											const_reverse_iterator;

		class value_compare // ngl, I yoinked this class straight off http://www.cplusplus.com/reference/map/map/value_comp/
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class MapBase;
		protected:
			Compare comp;
			explicit value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};
	// Constructors, destructors and operator=
		explicit MapBase(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _size(0){
			this->initmap();
		}
		MapBase (const MapBase& x) : _alloc(x._alloc), _comp(x._comp), _size(0) {
			this->initmap();
		}
		virtual	~MapBase() {
			this->clear();
			delete this->_first;
			delete this->_last;
		}
		MapBase& operator= (const MapBase& x) {
			if (this != &x) {
				this->clear();
				this->_alloc = x._alloc;
				this->_comp = x._comp;
				this->insert(x.begin(), x.end());
			}
			return (*this);
		}
	// Iterator functions
		iterator				begin() { return iterator(this->_first->parent); }
		const_iterator			begin() const { return const_iterator(this->_first->parent); }
		iterator				end() { return iterator(this->_last); }
		const_iterator			end() const { return const_iterator(this->_last); }
		reverse_iterator		rbegin() { return reverse_iterator(this->_last->parent); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->_last->parent); }
		reverse_iterator		rend() { return reverse_iterator(this->_first); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(this->_first); }
	// Capacity functions
		bool	empty() const { return (this->_size == 0); }
		size_type	size() const { return (this->_size); }
		virtual size_type	max_size() const { return this->_alloc.max_size() / 2; }
	// Modifier functions
		virtual void		erase(iterator position) {
			mapnode	*erase = this->findbyiterator(position);
			if (erase == this->_last)
				return ;
			this->RedBlackDelete(erase);
			delete erase;
			--this->_size;
		}
		virtual size_type	erase(const key_type& k) {
			iterator it = this->find(k);
			if (it == this->end())
				return 0;
			this->erase(it);
			return 1;
		}
		virtual void		erase(iterator first, iterator last) {
			while (first != last) {
				this->erase(first);
				++first;
			}
		}

		void		swap(MapBase& x) {
			itemswap(this->_size, x._size);
			itemswap(this->_first, x._first);
			itemswap(this->_root, x._root);
			itemswap(this->_last, x._last);
			itemswap(this->_alloc, x._alloc);
		}
		void		clear() {
			if (!this->empty()) {
				this->clear(this->_root);
				this->link_outer();
			}
		}

	// Observer functions
		key_compare		key_comp() const { return this->_comp; }
		value_compare	value_comp() const { return value_compare(this->_comp); }
	
	// Operation functions
	virtual iterator			find(const key_type& k) {
		mapnode	*it(this->_root);
		while (it && it != this->_first && it != this->_last) {
			if (this->itemcompare(k, it->data))
				it = it->left;
			else if (this->itemcompare(it->data, k))
				it = it->right;
			else return iterator(it);
		}
		return this->end();
	}
	virtual const_iterator	find(const key_type& k) const {
		mapnode	*it(this->_root);
		while (it && it != this->_first && it != this->_last) {
			if (this->itemcompare(k, it->data))
				it = it->left;
			else if (this->itemcompare(it->data, k))
				it = it->right;
			else return const_iterator(it);
		}
		return this->end();
	}
	virtual size_type	count(const key_type& k) const {
		const_iterator	it = this->begin();
		size_type		count = 0;

		while (it != this->end()) {
			if (this->itemcompare(k, *it) == false && this->itemcompare(*it, k) == false)
				++count;
			++it;
		}
		return count;
	}
	virtual iterator			lower_bound(const key_type& k) {
		iterator	it = this->begin(), ite = this->end();
		while (it != ite) {
			if (this->itemcompare(*it, k) == false)
				break ;
			++it;
		}
		return it;
	}
	virtual const_iterator	lower_bound(const key_type& k) const {
		const_iterator	it = this->begin(), ite = this->end();
		while (it != ite) {
			if (this->itemcompare(*it, k) == false)
				break ;
			++it;
		}
		return it;
	}
	virtual iterator			upper_bound(const key_type& k) {
		iterator	it = this->begin(), ite = this->end();
		while (it != ite) {
			if (this->itemcompare(k, *it))
				break ;
			++it;
		}
		return it;
	}
	virtual const_iterator			upper_bound(const key_type& k) const {
		const_iterator it = this->begin(), ite = this->end();
		while (it != ite) {
			if (this->itemcompare(k, *it))
				break ;
			++it;
		}
		return it;
	}
	virtual ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		return ft::make_pair(const_iterator(lower_bound(k)), const_iterator(upper_bound(k)));
	}
	virtual ft::pair<iterator,iterator>             equal_range (const key_type& k) {
		return ft::make_pair(iterator(lower_bound(k)), iterator(upper_bound(k)));
	}

	// Extra
		protected:
			void printBT() const {
				printBT("", this->_root, false);
				std::cerr << std::endl;
			}
			inline bool	itemcompare(const key_type& k, const ft::pair<Key, Value>& p) const {
				return this->key_comp()(k, p.first);
			}
			inline bool	itemcompare(const ft::pair<Key, Value>& p, const key_type& k) const {
				return this->key_comp()(p.first, k);
			}
			inline bool	itemcompare(const key_type& k1, const key_type& k2) const {
				return this->key_comp()(k1, k2);
			}
			inline bool	itemcompare(const ft::pair<Key, Value>& p1, const ft::pair<Key, Value>& p2) const {
				return this->key_comp()(p1.first, p2.first);
			}
			virtual mapnode			*findbyiterator(iterator position) {
				mapnode	*it(this->_root);
				while (it && it != this->_first && it != this->_last) {
					if (this->itemcompare(*position, it->data))
						it = it->left;
					else if (this->itemcompare(it->data, *position))
						it = it->right;
					else return (it);
				}
				return this->_last;
			}
			void printBT(const std::string& prefix, const mapnode* trav, bool isLeft) const {
				if (trav && trav != _first && trav != _last) {
					std::cerr << prefix;
					std::cerr << (isLeft ? "├L─" : "└R-" );
					// print the value of the node
					if (trav->colour == RED)
						std::cerr << _RED;
					else if (trav->colour == BLACK)
						std::cerr << _IWHITE << _GREY;
					std::cerr << trav->data.first << _END << std::endl ;
					// enter the next tree level - left and right branch
					printBT( prefix + (isLeft ? "│   " : "    "), trav->left, true);
					printBT( prefix + (isLeft ? "│   " : "    "), trav->right, false);
				}
			}
			void	initmap() {
				this->_first = new mapnode();
				this->_last = new mapnode();
				this->link_outer();
				this->_size = 0;
			}
			mapnode	*insert_root(const value_type& val) {
				this->_root = new mapnode(val, BLACK);
				++this->_size;
				_first->parent = _last->parent = this->_root;
				this->_root->left = _first;
				this->_root->right = _last;
				return this->_root;
			}
			void	erase_root() {
				if (this->_size == 1) {
					delete this->_root;
					this->link_outer();
					return ;
				}		
			}
			mapnode	*insert_left(mapnode *it, const value_type& val = value_type()) {
				mapnode *insert = new mapnode(val);
				insert->parent = it;
				insert->left = it->left;
				if (it->left)
					it->left->parent = insert;
				it->left = insert;
				++this->_size;
				 fixRedBlackViolations(insert);
				return insert;
			}
			mapnode	*insert_right(mapnode *it, const value_type& val = value_type()) {
				mapnode *insert = new mapnode(val);
				insert->parent = it;
				insert->right = it->right;
				if (it->right)
					it->right->parent = insert;
				it->right = insert;
				++this->_size;
				 fixRedBlackViolations(insert);
				return insert;
			}
			void	clear(mapnode *pos) {
				if (!pos)
					return ;
				clear(pos->left);
				clear(pos->right);
				if (pos != _first && pos != _last) {
					delete pos;
					--this->_size;
				}
			}
			void	link_outer() {
				this->_first->parent = this->_last;
				this->_last->parent = this->_first;
			}
			void	left_rotation(mapnode *x) {
				mapnode *y = x->right;
				x->right = y->left;
				if (x->right)
					x->right->parent = x;
				y->parent = x->parent;
				if (y->parent == 0) // x was root, now y is root
					this->_root = y;
				else if (x == y->parent->left) // x was left child
					y->parent->left = y;
				else // x was right child
					y->parent->right = y;
				y->left = x;
				x->parent = y;
			}
			void	right_rotation(mapnode *x) {
				mapnode *y = x->left;
				x->left = y->right;
				if (x->left)
					x->left->parent = x;
				y->parent = x->parent;
				if (y->parent == 0) // x was root, now y is root
					this->_root = y;
				else if (x == y->parent->left) // x was left child
					y->parent->left = y;
				else // x was right child
					y->parent->right = y;
				y->right = x;
				x->parent = y;
			}
			bool	is_validnode(mapnode *check) {
				return (check && check != this->_first && check != this->_last);
			}
			void	fixRedBlackViolations(mapnode *z) {
//				std::cerr << "printBT before fixviolations, z = " << z->data.first << "->>" << z->data.second << std::endl;
//				printBT();
				while (z != this->_root && z->colour == RED && z->parent->colour == RED) {
					mapnode *parent = z->parent;
					mapnode *grandpa = parent->parent;
					if (parent == grandpa->left) {
						mapnode *uncle = grandpa->right;
						if (is_validnode(uncle) && uncle->colour == RED) { // Case 1: uncle is red, recolour
//							std::cerr << _RED << _BOLD << "case A-1, checking z = " << z->data.first << "->" << z->data.second << std::endl;
							grandpa->colour = RED;
							parent->colour = BLACK;
							uncle->colour = BLACK;
							z = grandpa;
						}
						else if (z == parent->right) { // Case 2: node is right child of parent, left-rotation required
//							std::cerr << _RED << _BOLD << "case A-2, doing left rotation around " << parent->data.first << "->" << parent->data.second << std::endl;
							left_rotation(parent);
							z = parent;
							parent = z->parent;
						}
						else { // Case 3: node is left child of parent, right rotation required
//							std::cerr << _RED << _BOLD << "case A-2, doing right rotation around " << grandpa->data.first << "->" << grandpa->data.second << std::endl;
							right_rotation(grandpa);
							ft::itemswap(parent->colour, grandpa->colour);
						}
					}
					// Case B
					// Parent is right child of grandparent
					else if (parent == grandpa->right) {
						mapnode *uncle = grandpa->left;

						if (is_validnode(uncle) && uncle->colour == RED) { // Case 1: uncle is red, recolour
//							std::cerr << _RED << _BOLD << "case B-1, checking z = " << z->data.first << "->" << z->data.second << std::endl;
							grandpa->colour = RED;
							parent->colour = BLACK;
							uncle->colour = BLACK;
							z = grandpa;
						}
						else if (z == parent->left) { // Case 2: node is left child of parent, right-rotation required
//							std::cerr << _RED << _BOLD << "case B-2, doing right rotation around " << parent->data.first << "->" << parent->data.second << std::endl;
							right_rotation(parent);
							z = parent;
							parent = z->parent;
						}
						else {
//							std::cerr << _RED << _BOLD << "case B-2, doing left rotation around " << grandpa->data.first << "->" << grandpa->data.second << std::endl;
							left_rotation(grandpa);
							ft::itemswap(parent->colour, grandpa->colour);
							z = parent;
						}
					}
				}
				this->_root->colour = BLACK;
			}
			void	RedBlackTransplant(mapnode *u, mapnode *v) {
				if (u && u->parent == 0) // U is root
					this->_root = v;
				else if (u == u->parent->left) // u is left child
					u->parent->left = v;
				else // u is right child
					u->parent->right = v;
				if (v)
					v->parent = u->parent;
			}
			mapnode*	farleft(mapnode *x) {
				while (x->left)
					x = x->left;
				return x;
			}
			void	RedBlackDelete(mapnode *z) {
				mapnode *y(z);
				mapnode *x;
				Col  y_orignal_colour = y->colour;
				if (z->left == 0) { // no kids, or only right kid
					x = z->right;
					RedBlackTransplant(z, z->right);
				}
				else if (z->right == 0) { // only left kid
					x = z->left;
					RedBlackTransplant(z, z->left);
				}
				else { // two kids
					y = farleft(z->right);
					y_orignal_colour = y->colour;
					x = y->right;
					if (y->parent == z) { // y is a direct kid of z
						if (x) {
							x->parent = y; // changed from = z to = y
						}
					}
					else {
						RedBlackTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					RedBlackTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->colour = z->colour;
				}
				if (y_orignal_colour == BLACK) {
					RedBlackDeleteFixup(x);
				}
			}
			void	RedBlackDeleteFixup(mapnode *x) {
				if (x == 0)
					return ;
				while (x != this->_root && x->colour == BLACK) {
					if (x == x->parent->left) { // Case A
						mapnode *w = x->parent->right;
						if (w->colour == RED) { // Case 1
							w->colour = BLACK;
							x->parent->colour = RED;
							left_rotation(x->parent);
							w = x->parent->right;
						}
//						if (w->left == NULL || w->right == NULL) {
//							std::cerr << "w->left is " << w->left << ", w->right is " << w->right << std::endl;
//							std::cerr << "w is " << w << std::endl;
//							this->printBT();
//						}
						if (w->left && w->right && w->left->colour == BLACK && w->right->colour == BLACK) { // case 2
							w->colour = RED;
							x = x->parent;
						}
						else { // Case 3 or 4
							if (w->right && w->right->colour == BLACK && w->left) { // Case 3
								w->left->colour = BLACK;
								w->colour = RED;
								right_rotation(w);
								w = x->parent->right;
							}
							else { // Case 4
								w->colour = x->parent->colour;
								x->parent->colour = BLACK;
								if (w->right)
									w->right->colour = BLACK;
								left_rotation(x->parent);
								x = this->_root;
							}
						}
					}
					else { // Case B
						mapnode *w = x->parent->left;
						if (w->colour == RED) { // Case 1
							w->colour = BLACK;
							x->parent->colour = RED;
							right_rotation(x->parent);
							w = x->parent->left;
						}
						if (w->right->colour == BLACK && w->left->colour == BLACK) { // Case 2
							w->colour = RED;
							x = x->parent;
						}
						else { // Case 3 or 4
							if (w->left->colour == BLACK) { // Case 3
								w->right->colour = BLACK;
								w->colour = RED;
								left_rotation(w);
								w = x->parent->left;
							}
							else { // Case 4
								w->colour = x->parent->colour;
								x->parent->colour = BLACK;
								w->left->colour = BLACK;
								right_rotation(x->parent);
								x = this->_root;
							}
						}
					}
				}
				x->colour = BLACK;
			}

			mapnode			*_root;
			mapnode			*_first;
			mapnode			*_last;

			allocator_type	_alloc;
			key_compare		_comp;
			size_type		_size;
	};

/* Relational operators (map) */
template <class Key, class Value, class Compare, class Alloc>
bool operator== (const ft::MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& lhs, const ft::MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& rhs) {
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class Value, class Compare, class Alloc>
bool operator!= (const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& lhs, const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& rhs) {
	return !(lhs == rhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator<  (const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& lhs, const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class Value, class Compare, class Alloc>
bool operator>  (const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& lhs, const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& rhs) {
	return (rhs < lhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator<= (const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& lhs, const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& rhs) {
	return !(lhs > rhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator>= (const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& lhs, const MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& rhs) {
	return !(lhs < rhs);
}

template <class Key, class Value, class Compare, class Alloc>
void swap (MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& x, MapBase<Key,Value,ft::pair<Key, Value>, Compare, Alloc>& y) {
	itemswap(x._size, y._size);
	itemswap(x._first, y._first);
	itemswap(x._root, y._root);
	itemswap(x._last, y._last);
	itemswap(x._alloc, y._alloc);
}

} // ft namespace


#endif
