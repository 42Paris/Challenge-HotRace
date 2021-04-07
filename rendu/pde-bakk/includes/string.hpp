//
// Created by peerdb on 06-04-21.
//

#ifndef CHALLENGE_HOTRACE_STRING_HPP
#define CHALLENGE_HOTRACE_STRING_HPP
#include <cstdio>
extern "C" {
	#include "libft.h"
}

namespace ft {
	class string {
		size_t	_length;
		char*	_str;

		void	alloc_internal_string(const char* s) {
			free(this->_str);
			this->_length = ft_strlen(s);
			this->_str = ft_strdup(s);
			if (this->_str == NULL) {
				dprintf(2, "MALLOC FAILED\n");
				exit(1);
			}

		}
		void	alloc_internal_string(const string& s) {
			this->alloc_internal_string(s._str);
		}
	public:
		string() : _length(0), _str() {
			this->_str = ft_strdup("");
		}
		string(const char* str) : _length(0), _str(NULL) {
			this->alloc_internal_string(str);
		}
		string(const string& str) : _length(), _str(NULL) {
			this->alloc_internal_string(str);
		}

		~string() {
			free(_str);
		}
		string& operator=(const char* rhs) {
			free(this->_str);
			this->alloc_internal_string(rhs);
			return (*this);
		}
		string&	operator=(const string& rhs) {
			if (this != &rhs) {
				free(this->_str);
				this->alloc_internal_string(rhs);
			}
			return (*this);
		}

		int	compare(const string& rhs) const {
			size_t i = 0;

			while (this->_str[i] && rhs._str[i]) {
				if (this->_str[i] != rhs._str[i])
					break;
				++i;
			}
			return (this->_str[i] - rhs._str[i]);
		}

		const char* c_str() const {
			return (this->_str);
		}

		const char* data() const {
			return (this->_str);
		}

		size_t	size() const {
			return (this->_length);
		}
		size_t	length() const {
			return (this->_length);
		}

		void	clear() {
			if (this->_length > 0) {
				free(this->_str);
				this->_str = ft_strdup("");
			}
		}
	};

	std::ostream&	operator<<(std::ostream& out, const string& self) {
		out << self.c_str();
		return (out);
	}

	bool	operator==(const string& lhs, const string& rhs) { return (lhs.compare(rhs) == 0); }
	bool	operator!=(const string& lhs, const string& rhs) { return !(lhs == rhs); }
	bool	operator<(const string& lhs, const string& rhs) { return (lhs.compare(rhs) < 0); }
	bool	operator>(const string& lhs, const string& rhs) { return (rhs.compare(lhs)); }
	bool	operator<=(const string& lhs, const string& rhs) { return !(rhs.compare(lhs)); }
	bool	operator>=(const string& lhs, const string& rhs) { return !(lhs.compare(rhs)); }

}
#endif //CHALLENGE_HOTRACE_STRING_HPP
