/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 21:58:28 by peerdb        #+#    #+#                 */
/*   Updated: 2020/10/09 14:46:50 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.hpp"

namespace ft {

	static int	finish(std::string& line, int ret, std::string& buf)
	{
		buf = line.substr(line.find_first_of('\n') + 1, line.length() - line.find_first_of('\n') - 1);
		line = line.substr(0, line.find_first_of("\r\n"));
		return (ret > 0);
	}

	int	get_next_line(int fd, std::string& line)
	{
		int	ret = 1;
		static std::string m;

		line.clear();
		while (ret > 0) {
			line += m;
			if (line.find('\n') != std::string::npos) {
				return (finish(line, ret, m));
			}
			m.clear();
			char *tmp = (char*) malloc(BUFFER_SIZE + 1);
			if (!tmp)
				return (0);
			for (int i = 0; i < BUFFER_SIZE + 1; i++)
				tmp[i] = 0;
			ret = read(fd, tmp, BUFFER_SIZE);
			m = tmp;
			free(tmp);
		}
		return 0;
	}

}
