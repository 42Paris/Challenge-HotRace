/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 21:58:55 by peerdb        #+#    #+#                 */
/*   Updated: 2020/10/09 14:46:26 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_HPP
# define GET_NEXT_LINE_HPP
# include <string>
# include <iostream>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

namespace ft {
	int	get_next_line(int fd, std::string& line);
}

#endif
