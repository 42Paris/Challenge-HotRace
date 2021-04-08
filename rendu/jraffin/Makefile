# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by jraffin           #+#    #+#              #
#    Updated: 2021/04/07 19:54:35 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	hotrace

SRCDIR		=	.
OBJDIR		=	./obj
DEBUGDIR	=	./debugdir

SRCFILES	=	hotrace.c	\
				fullindex_tree.c

SRCS		=	$(addprefix $(SRCDIR)/,$(SRCFILES))
OBJS		=	$(addprefix $(OBJDIR)/,$(SRCFILES:.c=.o))
DEBUGOBJS	=	$(addprefix $(DEBUGDIR)/,$(SRCFILES:.c=.o))

CC			=	gcc
RM			=	rm

CFLAGS		=	-Wall -Wextra -Werror

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -Ofast -c $*.c -o $@

$(DEBUGDIR)/%.o	:	$(SRCDIR)/%.c | $(DEBUGDIR)
	$(CC) $(CFLAGS) -Og -g -c $*.c -o $@

$(NAME)			:	$(OBJS)
	$(CC) $(CFLAGS) -Ofast -o $(NAME) $(OBJS)

all				:	$(NAME) $(NAME).debug

debug			:	$(NAME).debug

$(NAME).debug	:	$(DEBUGOBJS)
	$(CC) $(CFLAGS) -Og -g -o $(NAME).debug $(DEBUGOBJS)

$(DEBUGDIR)		:
	mkdir $(DEBUGDIR)

$(OBJDIR)		:
	mkdir $(OBJDIR)

clean			:
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean			:	clean
	$(RM) -f $(NAME) $(NAME).debug

re				:	fclean $(NAME)

.PHONY			:	clean fclean re
