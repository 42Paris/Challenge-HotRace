# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 13:18:34 by abaudot           #+#    #+#              #
#    Updated: 2021/04/07 21:44:19 by abaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace
CC = gcc
CFLAGS = -Ofast -Wall -Werror -I.

SRCS = hotRace.c\
	   hashmap.c\
	   hashfunc.c

OBJS = $(SRCS:.c=.c)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
