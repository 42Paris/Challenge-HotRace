# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/04/07 22:25:20 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace

CC			=	gcc
CFLAGS		=	-O3 #-Wall -Werror -Wextra
LDFLAGS		=	#-g3 -fsanitize=address #-fsanitize=leak

OBJS		=	$(SRCS:.c=.o)
INCL		=	includes/
HEADER		=	$(INCL)$(NAME).h

LIBFT		=	libft.a
LIBFTDIR	=	libft/
LIBFTLINK	=	-L $(LIBFTDIR) -lft

SRCS		=	srcs/main.c					\
				srcs/utils.c

########################### EXEC
all:		$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LIBFTLINK)

########################### LIBARY
complib:
	$(MAKE) -C $(LIBFTDIR)

########################### OBJECTS
%.o:		%.c $(HEADER)
	$(CC) -c $(CFLAGS) $(LDFLAGS) -I $(INCL) -o $@ $<

########################### CLEAN
clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(OBJS)
	rm -f $(NAME) a.out

re:			fclean all
.PHONY:		re clean fclean test test_hotrace test_leaks
# .SILENT:

########################### TEST

test:		$(NAME)
	./$<

test_time:		$(NAME)
	time ./$<

test_leaks:	$(NAME)
	leaks -atExit -- ./$<
