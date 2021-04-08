/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:05:40 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/08 11:56:04 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "db.hpp"
#include "dictree.hpp"

void eval(db &db, std::string command)
{
	
	std::string key;
	std::string value;

	char *tmp;
	size_t test;
	if (!std::cin.good())
		exit(0);
	tmp = (char *)command.c_str();
	test = command.find("=");
	if (command[0] == '!')
	{
		if ( test != std::string::npos)
			tmp[test] = 0;
		db.pop(std::string(tmp));
	}
	else if ( test != std::string::npos)
	{
		if (command[test + 1] != 0)
		{
			value = tmp + (sizeof(char) * (test + 1));
			tmp[test] = 0;
			key = tmp;
			db.push(key, value);
		}
	}
	else
		db.query(command);
}

int main()
{
	db _db;
	for (std::string line; std::getline(std::cin, line);)
		eval(_db, line);
	return 0;
}
