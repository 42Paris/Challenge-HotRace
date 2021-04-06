/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListIterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 22:22:18 by peerdb        #+#    #+#                 */
/*   Updated: 2020/11/09 23:49:47 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include <memory>
# include <cstddef>
# ifdef QUEUE_HPP
#  include "../list/ListNode.hpp"
# else
#  include "ListNode.hpp"
# endif

namespace ft {
	
template <typename T, typename Pointer, typename Reference>
class ListIterator {
public:
	typedef ListIterator<T, Pointer, Reference>			this_type;
	typedef ListIterator<T, T*, T&>						iterator;
	typedef ListIterator<T, const T*, const T&>			const_iterator;
	typedef size_t										size_type;
	typedef ptrdiff_t									difference_type;
	typedef T											value_type;
	// typedef node<T>										node_type;
	typedef node<T>*									node_pointer;
	typedef Pointer										pointer;
	typedef Reference									reference;
	typedef std::bidirectional_iterator_tag				iterator_category;
	template <class T2, class A>						friend class list;
	// template <class T2, class P, class R>				friend class ListIterator;

// protected:
	node_pointer	ptr;
public:
	ListIterator( ) : ptr(NULL) { }
	ListIterator(const node_pointer elem) : ptr(elem) { }
	ListIterator(const iterator& x) : ptr(const_cast<node_pointer>(x.ptr)) {}
	~ListIterator( ) { }

	this_type&	operator=(const iterator& x) {
		this->ptr = x.ptr;
		return *this;
	}

	reference operator*() const { return ptr->data; }
	pointer   operator->() const { return &(this->ptr->data); }

	this_type& operator++() {
		ptr = ptr->next;
		return *this;
	}
	this_type  operator++(int) {
		this_type	out(*this);
		ptr = ptr->next;
		return out;
	}
	this_type& operator--() {
		ptr = ptr->prev;
		return *this;
	}
	this_type  operator--(int) {
		this_type	out(*this);
		ptr = ptr->prev;
		return out;
	}

	template<typename T2, typename P, typename R>
	friend inline bool operator==(const this_type& lhs, const ListIterator<T2, P, R>& rhs) {
		return (lhs.ptr == rhs.ptr);
	}
	template<typename T2, typename P, typename R>
	friend inline bool operator!=(const this_type& lhs, const ListIterator<T2, P, R>& rhs) { return !(lhs == rhs); }

protected:
	node_pointer	getnext() const { return ptr->next; }
	node_pointer	getprev() const { return ptr->prev; }
	node_pointer	getptr() const { return ptr; }
};


} //ft

#endif
