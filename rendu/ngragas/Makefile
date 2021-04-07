# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngragas <ngragas@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/04 20:29:14 by ngragas           #+#    #+#              #
#    Updated: 2021/04/07 20:56:17 by ngragas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace
CFLAGS = -Wall -Wextra -Werror -Ofast
SRC =	hotrace.c				\
		get_next_line_libc.c	\
# 		hotrace_utils.c			\

OBJ = $(SRC:.c=.o)

HEADER =	hotrace.h	\
			get_next_line_libc.h

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re