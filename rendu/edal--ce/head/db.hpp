/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:26:55 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 17:18:36 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_HPP
#define DB_HPP 

#include <iostream>
#include "dictree.hpp"


class db {

	public:
	
		db();
		~db();
		void		push(std::string const &key, std::string const &val);
		void 		pop(std::string key);
		void 		query(std::string const key);
		std::string search(std::string s) const;
	private :
		Dictree *_dt;
};
#endif