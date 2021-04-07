# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:49:24 by hthomas           #+#    #+#              #
#    Updated: 2021/04/07 22:39:59 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a
OBJS		=	$(SRCS:.c=.o)
INCLUDES	=	includes
HEADER		=	$(INCLUDES)/libft.h
CC			=	gcc
CFLAGS		=	-Ofast #-Wall -Wextra -Werror

# linked-list
SRCS		=	srcs/linked-list/ft_lstnew.c				\
				srcs/linked-list/ft_lstadd_front.c			\
				srcs/linked-list/ft_lstsize.c				\
				srcs/linked-list/ft_lstremove_one.c			\
				srcs/linked-list/ft_lstlast.c				\
				srcs/linked-list/ft_lstadd_back.c			\
				srcs/linked-list/ft_lstdelone.c				\
				srcs/linked-list/ft_lstclear.c				\
				srcs/linked-list/ft_lstiter.c				\
				srcs/linked-list/ft_lstmap.c				\

# get_next_line
SRCS		+=	srcs/gnl/get_next_line.c

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
	ar rc	$(NAME) $(OBJS)
	ranlib	$(NAME)

%.o:		%.c $(HEADER)
	$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ $<

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all
