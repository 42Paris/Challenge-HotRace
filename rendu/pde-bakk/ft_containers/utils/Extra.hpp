/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Extra.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 13:20:35 by peerdb        #+#    #+#                 */
/*   Updated: 2020/11/11 21:02:47 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_HPP
# define EXTRA_HPP
# include "Traits.hpp"
# include <cstddef>
# include <functional>

namespace ft {
	template<typename Iterator>
	ptrdiff_t distance(Iterator first, Iterator last) { //, typename ft::check_type<typename ft::iterator_traits<Iterator>::iterator_category>::type* = 0) {
		ptrdiff_t dist = 0;
		while (first != last) {
			++dist;
			++first;
		}
		return dist;
	}
	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n) { //typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
		if (n > 0)
			while (n) {
				++it;
				--n;
			}
		else while (n) {
			--it;
			++n;
		}
	}
	template< typename S >
	void	itemswap(S& var1, S& var2) {
		S tmpvar = var1;
		var1 = var2;
		var2 = tmpvar;
	}
	template<class value_type>
	const value_type&	min(const value_type& a, const value_type& b) {
		return (a < b ? a : b);
	}

	template<class value_type>
	const value_type&	max(const value_type& a, const value_type& b) {
		return (a < b ? b : a);
	}
	
	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};
  
	template<typename value_type>
	struct less: public ft::binary_function<value_type, value_type, bool> {
		bool	operator()(const value_type& x, const value_type& y) const {
			return (x < y);
		}
	};

	template<typename value_type>
	bool	is_equal(const value_type& a, const value_type& b) {
		return (a == b);
	}
	template<typename value_type>
	bool	less_than(const value_type& a, const value_type& b) {
		return (a < b);
	}
	template<typename value_type>
	bool	more_than(const value_type& a, const value_type& b) {
		return (a > b);
	}

	template <class Iterator1, class Iterator2>
	bool equal(Iterator1 first1, Iterator1 last1, Iterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

} // ft namespace

#endif
