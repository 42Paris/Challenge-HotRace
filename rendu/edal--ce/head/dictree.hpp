/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:00:21 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/08 13:16:34 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DICTREE_HPP
#define DICTREE_HPP

#include <cstdlib>
#include <iostream>
#define C_NB 95//223

class Dictree {
	
	public:
		Dictree();
		~Dictree();
		void	 	push(std::string key, std::string val);
		int			pop(std::string s);
		std::string search(std::string s);
	private : 
		char _tab[C_NB];
		char _etab[C_NB];
		std::string _str[C_NB];
		Dictree **_trees;
};
#endif