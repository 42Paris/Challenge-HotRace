/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal <edal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:33:18 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 19:43:18 by edal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "db.hpp"

db::db()
{
	_dt = new Dictree();
}

db::~db() 
{
	delete _dt;
}

void db::push(std::string const &key, std::string const &val)
{
	_dt->push(key, val);
}

std::string db::search(std::string const key) const
{
	return (_dt->search(key));
}

void db::query(std::string const key)
{
	std::string out = search(key);
	// std::cout << "OUT IS " << key.compare("Not found") << std::endl;
	
	if (out.compare("Not found") == 0)
	{
		std::cout << key << ": " << out << std::endl;
	}
	else
		std::cout << out << std::endl;
}

void db::pop(std::string key)
{
	_dt->pop(key.c_str() + sizeof(char));
}