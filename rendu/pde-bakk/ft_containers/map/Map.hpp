/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 23:49:18 by peerdb        #+#    #+#                 */
/*   Updated: 2020/11/07 23:41:31 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../utils/MapBase.hpp"

namespace ft {

template < class Key, class Value, class Compare = less<Key>, class Alloc = std::allocator<ft::pair<const Key,Value> > >
class map : public MapBase<const Key, Value, ft::pair<const Key, Value>, Compare, Alloc> {
	public:
		typedef MapBase<const Key, Value, ft::pair<const Key, Value>, Compare, Alloc>	Base;
		using typename	Base::key_type;
		using typename	Base::mapped_type;
		using typename	Base::value_type;
		using typename	Base::key_compare;
		using typename	Base::allocator_type;
		using typename	Base::reference;
		using typename	Base::const_reference;
		using typename	Base::pointer;
		using typename	Base::const_pointer;
		using typename	Base::mapnode;
		using typename	Base::iterator;
		using typename	Base::const_iterator;
		using typename	Base::reverse_iterator;
		using typename	Base::const_reverse_iterator;
		using typename	Base::difference_type;
		using typename	Base::size_type;

	// Constructors, destructors and operator=
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: Base(comp, alloc) {
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
					typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0)
				: Base(comp, alloc) {
			this->insert(first, last);
		}
		map (const map& x) : Base() {
			this->insert(x.begin(), x.end());
		}

		virtual	~map() { }

		map& operator= (const map& x) {
			if (this != &x) {
				this->clear();
				this->_alloc = x._alloc;
				this->_comp = x._comp;
				this->insert(x.begin(), x.end());
			}
			return (*this);
		}
	// Iterator functions: see MapBase

	// Capacity functions: see MapBase

	// Element access functions
		mapped_type&		operator[](const key_type& k) {
			return insert(ft::make_pair(k, mapped_type())).first->second;
		}

		mapped_type&		at(const key_type& k) {
			iterator it = this->find(k);
			if (it == Base::end())
				throw std::out_of_range("map::at:  key not found");
			return it->second;
		}
		const mapped_type&	at(const key_type& k) const {
			const_iterator it = this->find(k);
			if (it == Base::end())
				throw std::out_of_range("map::at:  key not found");
			return it->second;
		}
	// Modifier functions: see Base
		ft::pair<iterator, bool>	insert(const value_type& val) {
			if (this->_size == 0)
				return (ft::make_pair(iterator(Base::insert_root(val)), true));
			mapnode	*it(this->_root);
			while (it) {
				if (key_compare()(val.first, it->data.first)) {
					if (it->left && it->left != this->_first)
						it = it->left;
					else return ft::make_pair(iterator(Base::insert_left(it, val)), true);
				}
				else if (key_compare()(it->data.first, val.first)) {
					if (it->right && it->right != this->_last)
						it = it->right;
					else return ft::make_pair(iterator(Base::insert_right(it, val)), true);
				}
				else break ;
			}
			return ft::make_pair(iterator(it), false);
		}
		iterator	insert(iterator position, const value_type& val) {
			(void)position;
			return insert(val).first;
		}
		template <class InputIterator>
		void		insert(InputIterator first, InputIterator last, typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			while (first != last) {
				insert(*first);
				++first;
			}
		}

	// Observer functions: see Base

	// Operation functions: see Base

	};

/* Relational operators (map): see Base */

} // ft namespace


#endif
