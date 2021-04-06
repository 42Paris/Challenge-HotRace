//
// Created by peerdb on 06-04-21.
//

#ifndef CHALLENGE_HOTRACE_STRING_HPP
#define CHALLENGE_HOTRACE_STRING_HPP

extern "C" {
	#include "libft.h"
};

namespace ft {
	class string {
		size_t	_length;
		char*	_str;

		void	alloc_internal_string(const char* s) {
			free(this->_str);
			this->_length = ft_strlen(s);
			this->_str = ft_strdup(s);
		}
		void	alloc_internal_string(const string& s) {
			this->alloc_internal_string(s._str);
		}
	public:
		string() : _length(0), _str(ft_strdup("")) { }
		string(explicit const char* str) : _length(ft_strlen(str), _str(ft_strdup(str)) ) { }
		string(explicit string str) : _length(str._length), _str(ft_strdup(str._str)) { }
		~String() {
			free(_str);
		}
		string&	operator=(const string& rhs) {
			if (this != &rhs) {
				free(this->_str);
				this->alloc_internal_string(rhs);
			}

		}
	};

}
#endif //CHALLENGE_HOTRACE_STRING_HPP
