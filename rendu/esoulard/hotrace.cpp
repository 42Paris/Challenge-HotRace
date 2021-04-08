/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:09:10 by esoulard          #+#    #+#             */
/*   Updated: 2021/04/08 13:00:56 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Map.hpp"
#include <string>
#include <cstring>
#include <iostream>


void add_entry(char *in_c, ft::Map<std::string, std::string >&db, char *equal) {

    *equal = '\0';
    ++equal;
    db[std::string(in_c)] = std::string(equal);
}

void get_entry(std::string &in_str, ft::Map<std::string, std::string >&db) {
    
    ft::Map< std::string, std::string >::iterator it = db.find(in_str);

    if (it != db.end())
        std::cout << (*it).second << "\n";
    else
        std::cout << in_str << ": Not found" << "\n";
}

int main() {

    ft::Map<std::string, std::string > db;
    std::string in_str;
    char *in_c;
    char *equal;

    while (1) {
        
        equal = NULL;

        std::getline(std::cin, in_str);
        if (!std::cin)
            break ;

        in_c = &in_str[0];
        if (in_c[0] == '!') 
            db.erase(&in_str[1]);
        else if ((equal = strchr(in_c, '=')))
            add_entry(in_c, db, equal);
        else
            get_entry(in_str, db);

        in_str = std::string("");
        in_c[0] = '\0';
    }
    return 0;
}