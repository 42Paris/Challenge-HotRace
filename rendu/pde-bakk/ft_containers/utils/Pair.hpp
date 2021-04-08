/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <pde-bakk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 22:13:04 by pde-bakk      #+#    #+#                 */
/*   Updated: 2020/11/07 23:57:22 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_PAIR_HPP
# define FT_CONTAINERS_PAIR_HPP
# include <utility>

namespace ft {

	template<class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second() {}

		template<class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) { }
		
		template<class U, class V>
		pair(const std::pair<U, V>& pr) : first(pr.first), second(pr.second) { }

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		pair &operator=(const pair &x) {
			if (this != &x) {
				this->first = x.first;
				this->second = x.second;
			}
			return *this;
		}
	};

	template<class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template<class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template<class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs == rhs); }

	template<class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (rhs < lhs); }

	template<class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(rhs < lhs); }

	template<class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs < rhs); }

	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}
} //ft namespace
#endif //FT_CONTAINERS_PAIR_HPP
