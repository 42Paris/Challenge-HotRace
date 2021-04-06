/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 15:19:02 by peerdb        #+#    #+#                 */
/*   Updated: 2020/11/04 15:33:07 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstddef>
# include "RandomAccessIterator.hpp"
# include "ReverseIterator.hpp"
# include "Traits.hpp"
# include "Extra.hpp"
# include <stdexcept>
#include <iostream>

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef T												value_type;
		typedef	Alloc											allocator_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef value_type*										pointer;
		typedef const value_type*								const_pointer;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;
		typedef RandomAccessIterator<T, T*, T&>					iterator;
		typedef RandomAccessIterator<T, const T*, const T&>		const_iterator;
		typedef ReverseRAI<iterator>							reverse_iterator;
		typedef ReverseRAI<const_iterator >						const_reverse_iterator;

		explicit vector (const allocator_type& alloc = allocator_type()) : _array(0), _size(0), _capacity(0), _alloc(alloc) {
		}
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
			this->_array = new value_type[n]();
			for (size_type i = 0; i < n; i++)
				this->_array[i] = val;
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) : _array(0), _size(0), _capacity(0), _alloc(alloc) {
			this->_capacity = ft::distance(first, last);
			this->_size = _capacity;
			this->_array = new value_type[this->_capacity];
			this->assign(first, last);
		}
		vector (const vector& x) : _array(0), _size(0), _capacity(0), _alloc(x._alloc) {
			*this = x;
		}
		vector&	operator=(const vector& x) {
			delete[] this->_array;
			this->_array = new value_type[x._capacity];
			this->_capacity = x._capacity;
			this->_size = 0;
			this->assign(x.begin(), x.end());
			return *this;
		}
		~vector() {
			delete[] this->_array;
		}
	/* Iterators */
		iterator begin() {
			return iterator(this->_array);
		}
		const_iterator begin() const {
			return const_iterator(this->_array);
		}
		iterator end() {
			return iterator(&this->_array[this->_size]);
		}
		const_iterator end() const {
			return const_iterator(&this->_array[this->_size]);
		}
		reverse_iterator		rbegin() {
			return reverse_iterator(&this->_array[this->_size - 1]);
		}
		const_reverse_iterator	rbegin() const {
			return reverse_iterator(&this->_array[this->_size - 1]);
		}
		reverse_iterator		rend() {
			return reverse_iterator(this->_array - 1);
		}
		const_reverse_iterator	rend() const {
			return reverse_iterator(this->_array - 1);
		}
	/* Capacity */
		size_type	size() const {
			return this->_size;
		}
		size_type	max_size() const {
			return this->_alloc.max_size();
		}
		void		resize (size_type n, value_type val = value_type()) {
			while (n < this->_size)
				pop_back();
			if (n > this->_capacity)
				reserve(n);
			while (n > this->_size)
				push_back(val);
		}
		size_type	capacity() const {
			return this->_capacity;
		}
		bool	empty() const {
			return (!(this->_size));
		}
		void		reserve(size_type n) {
			if (n <= this->_capacity)
				return ;
			n = ft::max(n, this->_capacity * 2);
			pointer tmp = new value_type[n];
			for (size_type i = 0; i < this->_size; i++) 
				tmp[i] = this->_array[i];
			delete[] this->_array;
			this->_array = tmp;
			this->_capacity = n;
		}
	/* Element Access */
		reference		operator[](size_type n) {
			return this->_array[n];
		}
		const_reference	operator[](size_type n) const {
			return this->_array[n];
		}
		reference		at(size_type n) {
			if (n >= this->_size)
				throw std::out_of_range("out of range");
			return this->_array[n];
		}
		const_reference	at(size_type n) const {
			if (n >= this->_size)
				throw std::out_of_range("out of range");
			return this->_array[n];
		}
		reference		front() {
			return this->_array[0];
		}
		const_reference	front() const {
			return this->_array[0];
		}
		reference		back() {
			return this->_array[this->_size - 1];
		}
		const_reference	back() const {
			return this->_array[this->_size - 1];
		}
	/* Modifiers */
		template <class InputIterator>
		void	assign (InputIterator first, InputIterator last,
				typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			this->clear();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		void	assign(size_type n, const value_type& val) {
			this->clear();
			while (n) {
				push_back(val);
				--n;
			}
		}
		void	push_back(const value_type& val) {
			if (this->_size == this->_capacity) {
				if (this->_size == 0)
					reserve(1);
				else
					reserve(this->_capacity * 2);
			}
			this->_array[this->_size] = val;
			this->_size++;
		}
		void	pop_back() {
			this->_size--;
		}
		iterator insert (iterator position, const value_type& val) {
			size_type n = ft::distance(begin(), position);
			insert(position, 1, val);
			return (iterator(&this->_array[n]));
		}
		void insert (iterator position, size_type n, const value_type& val) {
			vector tmp(position, end());
			this->_size -= ft::distance(position, end());
			while (n) {
				push_back(val);
				--n;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) {
				push_back(*it);
				++it;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			vector tmp(position, end());
			this->_size -= ft::distance(position, end());
			while (first != last) {
				push_back(*first);
				++first;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) {
				push_back(*it);
				++it;
			}
		}
		iterator	erase(iterator position) {
			iterator out(position);
			while (position != end() - 1) {
				*position = *(position + 1);
				++position;
			}
			--this->_size;
			return out;
		}
		iterator	erase(iterator first, iterator last) {
			iterator out(last);
			while (last != end()) {
				*first = *last;
				++first;
				++last;
			}
			this->_size -= ft::distance(first, last);
			return out;
		}
		void swap (vector& x) {
			vector tmp(x);
			x = *this;
			*this = tmp;
		}
		void	clear() {
			while (this->_size)
				pop_back();
		}
	/* Non-member function overloads */
	private:
		pointer			_array;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;
	};

template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
	vector<T,Alloc>	tmp(x);
	x = y;
	y = tmp;
}

}


#endif
