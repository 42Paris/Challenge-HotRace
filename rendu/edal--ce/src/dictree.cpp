/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal <edal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:00:17 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 19:42:56 by edal             ###   ########.fr       */
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

std::string Dictree::search(std::string key) const
{
	Dictree *tmp;
	char *tab;
	if (key[0] < 0)
	{
		key[0] *= -1;
		tab = (char*)_etab;
	}
	else
		tab = (char*)_tab;
	if (key[1] == 0)
	{
		if (tab[key[0] - ' '] && _str[key[0] - ' '] != "")
		{
			return (_str[key[0] - ' ']);
		}
		else
			return ("Not found");
	}
	else if (tab[key[0] - ' ' ] != 0)
	{
		tmp = _trees[key[0] - ' '];
		if ( tmp != 0)
			return (tmp->search(key.c_str() + 1 * sizeof(char)));
	}
	return ("Not found");
}

int Dictree::pop(std::string key)
{
	Dictree *tmp;
	char *tab;
	if (key[0] < 0)
	{
		key[0] *= -1;
		tab = (char*)_etab;
	}
	else
		tab = (char*)_tab;

	if (key[1] == 0)
	{
		if (tab[key[0] - ' '] && _str[key[0] - ' '] != "")
		{
			_str[key[0] - ' ']= "";
			tab[key[0] - ' '] -= 1;	
			return (1);
		}
		else
			return (0);
	}
	else if (tab[key[0] - ' ' ] != 0)
	{
		tmp = _trees[key[0] - ' '];
		if ( tmp != 0)
			return (tmp->pop(key.c_str() + 1 * sizeof(char)));
	}
	return (0);
}

void Dictree::push(std::string key, std::string val)
{
	char *tab = (char*)_tab;
	if (key[0] < 0)
	{
		key[0] *= -1;	
		tab = (char*)_etab;
	}
	if (key[1] == 0)
	{
		tab[key[0] - ' ']++;
		if (_str[key[0] - ' '] == "")
			_str[key[0] - ' '] = val;
		return;
	}
	if (tab[key[0] - ' ' ] != 0 && _trees[key[0] - ' '] != 0 )
		_trees[key[0] - ' ']->push(key.c_str() + 1 * sizeof(char),val);
	else
	{
		if (_trees[key[0] - ' '] == 0)
			_trees[key[0] - ' '] = new Dictree();
		tab[key[0] - ' ' ]++;	
		_trees[key[0] - ' ']->push(key.c_str() + 1 * sizeof(char),val);
	}

}