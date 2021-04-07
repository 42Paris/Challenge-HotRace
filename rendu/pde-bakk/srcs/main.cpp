#include "map/Map.hpp"
extern "C" {
	#include "get_next_line.h"
	#include "libft.h"
}
#include <iostream>
#include <string>
#include <cstdio>
#include "string.hpp"

#ifndef STRING
# define STRING ft
#endif
using STRING::string;

ft::map<string, string>	dict;

void	new_entry(char* line, size_t i) {
	line[i] = '\0';
	string	key = line,
			value = line + i + 1;
//	key.assign(line, i);
//	value.assign(line + i + 1);
	line[i] = '=';
	dict.insert(ft::make_pair(key, value)); // insert over [] so it wont add the new value if the key already existed

}

void	get_entry(char* line) {
	try {
		string valeur = dict.at(line);
		std::cout << valeur << "\n";
	} catch (std::exception& e) {
		std::cout << line << ": Not found\n";
	}
}

void	parse(char* line) {
	if (line[0] == '!') {
		dict.erase(line + 1);
	} else {
		size_t i = 0;
		while (line[i]) {
			if (line[i] == '=') {
				if (line[i + 1] == '=')
					++i;
				else
					break;
			}
			++i;
		}
		if (line[i] == '=')
			new_entry(line, i);
		else
			get_entry(line);
	}
}

int main() {
	char*	line;
	while (get_next_line(0, &line)) {
		parse(line);
		free(line);
		line = NULL;
	}
	free(line);
	return (0);
}
