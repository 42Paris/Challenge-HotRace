/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:37:03 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/12 13:19:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
#define MAPNODE_HPP

namespace ft {

	template < class Key, class T >
	class Pair {
		public:
			Pair() : first(), second() {};
			Pair(Pair<Key, T> const &other) : first(other.first), second(other.second) {};
			Pair(Key const &key, T const &content) : first(key), second(content) {};
			virtual ~Pair() {};
			
			Pair &operator=(Pair const &other) {

				first = other.first; 
				second = other.second;
				return (*this);
			}
			Pair &operator=(T const &other) {

				second = other.second;
				return (*this);
			}

			Key first;
			T second;
	};

	template < class Key, class T, class Compare = std::less<Key> >
	class MapNode {

		public:
			typedef Key 												key_type;
			typedef T 													mapped_type;
			typedef ft::Pair<const key_type, mapped_type> 				value_type;
			typedef Compare 											key_compare;
			typedef MapNode<Key, T, Compare> 							node_type;

			MapNode() 							: _value(), _up(NULL), _left(NULL), _right(NULL) {};
			MapNode(value_type const &value) 	: _value(value), _up(NULL), _left(NULL), _right(NULL) {};
			MapNode(node_type const &src) 		: _value(src._value), _up(src._up), _left(src._left), _right(src._right) {};
			~MapNode() {}

			MapNode &operator=(MapNode const &src) {

				this->_value = src._value;
				this->_up = src._up;
				this->_left = src._left;
				this->_right = src._right;

				return (*this);
			}

			MapNode &operator=(mapped_type const &src) {

				this->_value.second = src;
				return (*this);
			}

			value_type &getValue() {

				return _value;
			};

			value_type const &getValue() const {

				return _value;
			};
			
			MapNode 		*getLeft() {

				return _left;
			};

			MapNode const 	*getLeft() const {

				return _left;
			};

			MapNode	*getRight() {

				return _right;
			};

			MapNode const	*getRight() const {

				return _right;
			};

			void resetNode() {

				this->_value = value_type();
				this->_up = NULL;
				this->_left = NULL;
				this->_right = NULL;
			};

			node_type 		*getPrev(node_type *cur) {

				node_type *ret = cur;

				if (ret->_left) {
					ret = ret->_left;
					while (ret->_right)
						ret = ret->_right;
					return ret;
				}
				else if (ret->_up) {
					node_type *prev = ret;
					ret = ret->_up;
					while (_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type 	const *getPrev(node_type *cur) const {

				node_type *ret = cur;

				if (ret->_left) {
					ret = ret->_left;
					while (ret->_right)
						ret = ret->_right;
					return ret;
				}
				else if (ret->_up) {
					node_type *prev = ret;
					ret = ret->_up;
					while (_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type const		*getNext(node_type const *cur) const {

				node_type const *ret = cur;

				if (ret->_right) {
					ret = ret->_right;
					while (ret->_left)
						ret = ret->_left;
					return ret;
				}
				else if (ret->_up) {
					node_type const *prev = ret;
					ret = ret->_up;
					while (!_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type 		*getNext(node_type *cur) {

				node_type *ret = cur;

				if (ret->_right) {
					ret = ret->_right;
					while (ret->_left)
						ret = ret->_left;
					return ret;
				}
				else if (ret->_up) {
					node_type *prev = ret;
					ret = ret->_up;
					while (!_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type 		*getLast(node_type *cur, node_type *end) {

				node_type *last = cur;
				if (last->_right && last->_right != end)
					last = last->_right;
				return last;
			};

			node_type const 	*getLast(node_type *cur, node_type *end) const {

				node_type *last = cur;
				if (last->_right && last->_right != end)
					last = last->_right;
				return last;
			};

			node_type 	*getBegin(node_type *cur) {
				
				node_type *beg = cur;
				while (beg->_left)
					beg = beg->_left;
				return beg;
			};

			node_type const 	*getBegin(node_type *cur) const {

				if (cur->_left)
					getBegin(cur->_left);
				return cur;
			};

			node_type 	*getParent() {

				return _up;
			};

			node_type const 	*getParent() const {

				return _up;
			};

			void 	setEnd(node_type *cur) {

				node_type *last = getLast(cur, this);
				last->_right = this;
				this->_up = last; 
			};

			/*
				less returns bool x<y
				so if less(key, cur->value), go left
				if !left go right
			*/

			node_type *nextExtremity(node_type *cur, node_type *toDel, node_type *end) {

				if ((!(cur->_right) || cur->_right == end) && !(cur->_left) && (cur != toDel))
					return cur ;
				if ((!(cur->_right) || cur->_right == end) && !(cur->_left) && (cur == toDel))
					return NULL ;
				if (cur->_left)
					cur = nextExtremity(cur->_left, toDel, end);
				if (cur->_right && cur->_right != end)
					cur = nextExtremity(cur->_right, toDel, end);
				if (cur && cur != toDel)
					return cur;
				return NULL; 
			};

			void	ditchParent(node_type *cur) {

				cur->_up = NULL;
			};

			void	ditchKids(node_type *cur) {

				cur->_left = NULL;
				cur->_right = NULL;
			};

			void	ditchKid(node_type *kid) {

				if (this->_left == kid)
					this->_left = NULL;
				else if (this->_right == kid)
					this->_right = NULL;
			};

			void	ditchAll(node_type *cur) {

				ditchKids(cur);
				ditchParent(cur);
			};

			node_type *addNode(node_type *cur, node_type *node, node_type *end) {

				if (_comp(node->_value.first, cur->_value.first) && cur->_left)
					addNode(cur->_left, node, end);
				if (_comp(cur->_value.first, node->_value.first) && cur->_right != end)
					addNode(cur->_right, node, end);

				if (!_comp(cur->_value.first, node->_value.first) && !_comp(cur->_value.first, node->_value.first))
					return cur;
				
				if (_comp(node->_value.first, cur->_value.first) && !cur->_left)
					return cur->_left;
				if (_comp(cur->_value.first, node->_value.first) && (!cur->_right || cur->_right == end))
					return cur->_right;

				return NULL; 
			}

			node_type *findSpot(node_type *cur, key_type k, node_type *beg, node_type *end) {
				
				if (!_comp(cur->_value.first, k) && (!cur->_left || cur == beg)) 
					return cur;
				if (_comp(cur->_value.first, k) && (!cur->_right || cur->_right == end)) 
					return cur;

				if (_comp(k, cur->_value.first) && cur->_left && cur != beg)
					return findSpot(cur->_left, k, beg, end);
				if (_comp(cur->_value.first, k) && cur->_right && cur->_right != end)
					return findSpot(cur->_right, k, beg, end);

				return NULL;
			};

		
			void adopt(node_type *kid, node_type *end) {
				
				if (kid && kid != end && _comp(kid->_value.first, this->_value.first))
					this->_left = kid;
				else {
					if (this->_right == end) {
						kid->_right = end;
						end->_up = kid;
					}
					this->_right = kid;
				}
				if (kid)
					kid->_up = this;
			};

			void initRoot(node_type *begin, node_type *end) {

				this->_left = NULL;
				begin = this;
				this->_right = end;
				end->_up = this;

			}

			node_type *findKey(node_type *cur, key_type const &key, node_type *end) {

				if (cur == end)
					return NULL;
								
				if (!_comp(cur->_value.first, key) && !_comp(key, cur->_value.first))
					return cur;

				if (_comp(key, cur->_value.first) && cur->_left && cur->_left != end)
					return findKey(cur->_left, key, end);
				if (_comp(cur->_value.first, key) && cur->_right && cur->_right != end)
					return findKey(cur->_right, key, end);

				return NULL;
			}

			void deleteAll(node_type *cur, node_type *end) {

				if (!cur || cur == end)
					return ;
				deleteAll(cur->_left, end);
				deleteAll(cur->_right, end);
				delete cur;
			}
                                 
			void 	swapNodes(node_type *one, node_type *two) {
		
				MapNode *stock = two->_next;

				one->_next = two->_next;
				two->_next = one;

				if (one->_prev)
					one->_prev->_next = two;
				if (stock)
					stock->_prev = one;

				stock = one->_prev;
				one->_prev = two;
				two->_prev = stock;
			};
			
		private :

			value_type 		_value;
			
			node_type 		*_up;
			node_type 		*_left;
			node_type 		*_right;
			
			key_compare 	_comp;
			
	};
};

#endif