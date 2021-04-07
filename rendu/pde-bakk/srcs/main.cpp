#include "map/Map.hpp"
extern "C" {
	#include "get_next_line.h"
	#include "libft.h"
}
#include <iostream>
#include <string>

ft::map<std::string, std::string>	dict;

void	new_entry(char* line, size_t i) {
	std::string	key,
				value;
	key.assign(line, i);
	value.assign(line + i + 1);
	dict.insert(ft::make_pair(key, value)); // insert over [] so it wont add the new value if the key already existed
}

void	get_entry(char* line) {
	try {
		std::string valeur = dict.at(line);
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
}
