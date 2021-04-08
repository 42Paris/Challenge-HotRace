/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:00:17 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/08 13:30:51 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictree.hpp"

Dictree::Dictree() 
{
	_trees = (Dictree **)malloc(sizeof(Dictree *) * C_NB);
	for (int i = 0; i < C_NB; i++)
	{
		_tab[i] = 0;
		_etab[i] = 0;
		_trees[i] = 0;
		_str[i] = "";
	}
}

Dictree::~Dictree() 
{
	for (int i = 0; i < C_NB; i++)
		delete	_trees[i];
	free(_trees);
}

std::string Dictree::search(std::string key)
{
	char *tab;
	char &k0 = key[0];
	tab = (k0 < 0) ? _etab : _tab;
	k0 = (k0 < 0) ? (k0 * -1) - ' ': k0 - ' ';
	char &tk0 = tab[k0];
	std::string &sk0 = _str[k0];
	if (key[1] == 0)
	{
		if (tk0 && sk0 != "")
			return (sk0);
		else
			return ("Not found");
	}
	else if (tk0 != 0)
		if ( _trees[k0] != 0)
			return (_trees[k0]->search(key.c_str() + 1 * sizeof(char)));
	return ("Not found");
}

int Dictree::pop(std::string key)
{
	char &k0 = key[0];
	char *tab = (k0 < 0) ? _etab : _tab;
	k0 = (k0 < 0) ? (k0 * -1) - ' ': k0 - ' ';
	char &tk0 = tab[k0];
	std::string &sk0 = _str[k0];
	if (key[1] == 0)
	{
		if (tk0 && sk0 != "")
		{
			sk0 = "";
			tk0 -= 1;
			return (1);
		}
	}
	else if (tk0 != 0)
		if ( _trees[k0] != 0)
			return (_trees[k0]->pop(key.c_str() + 1 * sizeof(char)));
	return (0);
}

void Dictree::push(std::string key, std::string val)
{
	char &k0 = key[0];
	char *tab = (k0 < 0) ? _etab : _tab;
	k0 = (k0 < 0) ? (k0 * -1) - ' ': k0 - ' ';
	char &tk0 = tab[k0];
	std::string &sk0 = _str[k0];
	if (key[1] == 0)
	{
		tk0++;
		if (sk0== "")
			sk0 = val;
		return;
	}
	if (tk0 != 0 && _trees[k0] != 0 )
		_trees[k0]->push(key.c_str() + 1 * sizeof(char),val);
	else
	{
		if (_trees[k0] == 0)
			_trees[k0] = new Dictree();
		tk0++;	
		_trees[k0]->push(key.c_str() + 1 * sizeof(char),val);
	}
}