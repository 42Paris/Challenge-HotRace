/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:19:24 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/26 10:10:26 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 128

int		get_next_line(int fd, char **line);
int		ft_loadbuffer(int fd, char **buffer, int *i);
int		ft_clean(char **buffer);
int		ft_initialize(int fd, char **buffer, char **line, int *i);
char	*ft_realloc(int size, char **line);
int		ft_resize(char **line, int j, char **buffer);
int		ft_reader(int *i, char **buffer, char **line, int fd);
void	ft_reset(char **buffer, int	*fdc, int *i, int fd);

#endif
