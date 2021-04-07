/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:05:40 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 17:44:05 by edal--ce         ###   ########.fr       */
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
	int test;
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

void feed(db &db)
{
	std::ifstream file("./dicos/generated-1");
	std::string line;
	int i = 0;
	if (file)
    {

		while (getline(file, line))
		{
			i++;
			if ((i % 1000) == 0)
				std::cout << "Processing line " << i << "/1100000 " << i / 1100000 << "%"<< std::endl;
			eval(db, line);
		}
	    file.close();
    }
	else 
		std::cout << "File open failed" << std::endl;
}

void prompt(db &db)
{
	std::string command;
	while (command != "EXIT")
	{
		std::getline(std::cin, command);
		eval(db, command);
	}	
}

int main()
{
	db test;
	prompt(test);
	return 0;
}