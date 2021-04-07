# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atruphem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 15:03:12 by atruphem          #+#    #+#              #
#    Updated: 2021/04/07 22:23:54 by toni             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace 

OBJ = clean.o ft_putchar_fd.o ft_putstr_fd.o ft_strcmp.o ft_strlcpy.o ft_strlen.o get_next_line.o get_next_line_utils.o main.o rb_ftcs.o rb_insert.o rb_rotations.o

CCFLAGS = -Wall -Werror -Wextra

CC = clang

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CCFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
