/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListNode.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 12:18:41 by peerdb        #+#    #+#                 */
/*   Updated: 2020/11/04 16:38:05 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft {
	template <typename T>
	class node {
	public:
		T			data;
		node*		next;
		node*		prev;

		explicit node(const T &val = T()) : data(val), next(0), prev(0) { }
		node(const node &other) : data(other.data), next(other.next), prev(other.prev) { }
		~node() { }

		node&	operator=(const node& rhs) {
			if (this != &rhs) {
				this->data = rhs.data;
				this->next = rhs.next;
				this->prev = rhs.prev;
			}
			return *this;
		}
		bool	operator==(const node& rhs) const {
			return (this->data == rhs.data && this->next = rhs.next && this->prev == rhs.prev);
		}
		bool	operator!=(const node& rhs) const {
			return *this != rhs;
		}
		node*	getnext() {
			return this->next;
		}
		node*	getprevious() {
			return this->prev;
		}
	};
}

#endif
