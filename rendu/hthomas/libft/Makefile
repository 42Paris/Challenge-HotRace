# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:49:24 by hthomas           #+#    #+#              #
#    Updated: 2021/03/27 17:42:20 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a
OBJS		=	$(SRCS:.c=.o)
INCLUDES	=	includes
HEADER		=	$(INCLUDES)/libft.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# io
SRCS		=	srcs/io/ft_print_tabint.c					\
				srcs/io/ft_putnbr.c							\
				srcs/io/ft_putnbr_fd.c						\
				srcs/io/ft_putnbr_unsigned_fd.c				\
				srcs/io/ft_putnbr_unsigned.c				\
				srcs/io/ft_putchar.c						\
				srcs/io/ft_putchar_fd.c						\
				srcs/io/ft_putendl_fd.c						\
				srcs/io/ft_puthex.c							\
				srcs/io/ft_putpointer.c						\
				srcs/io/ft_putstrn_fd.c						\
				srcs/io/ft_putstr_fd.c						\
				srcs/io/ft_putstr.c							\
				srcs/io/ft_putstrn.c						\
				srcs/io/ft_print_tabstr.c					\


# linked-list
SRCS		+=	srcs/linked-list/ft_lstnew.c				\
				srcs/linked-list/ft_lstadd_front.c			\
				srcs/linked-list/ft_lstsize.c				\
				srcs/linked-list/ft_lstlast.c				\
				srcs/linked-list/ft_lstadd_back.c			\
				srcs/linked-list/ft_lstdelone.c				\
				srcs/linked-list/ft_lstclear.c				\
				srcs/linked-list/ft_lstiter.c				\
				srcs/linked-list/ft_lstmap.c				\

# linked-list-doubly
SRCS		+=	srcs/linked-list-doubly/ft_dlstnew.c		\
				srcs/linked-list-doubly/ft_dlstadd_front.c	\
				srcs/linked-list-doubly/ft_dlstsize.c		\
				srcs/linked-list-doubly/ft_dlstlast.c		\
				srcs/linked-list-doubly/ft_dlstadd_back.c	\
				srcs/linked-list-doubly/ft_dlstdelone.c		\
				srcs/linked-list-doubly/ft_dlstclear.c		\
				srcs/linked-list-doubly/ft_dlstiter.c		\
				srcs/linked-list-doubly/ft_dlstmap.c		\
				srcs/linked-list-doubly/ft_dlstremove_one.c	\

# memory
SRCS		+=	srcs/memory/ft_swap.c						\
				srcs/memory/ft_memset.c						\
				srcs/memory/ft_memcpy.c						\
				srcs/memory/ft_memccpy.c					\
				srcs/memory/ft_memmove.c					\
				srcs/memory/ft_memchr.c						\
				srcs/memory/ft_memcmp.c						\
				srcs/memory/ft_calloc.c						\
				srcs/memory/ft_bzero.c						\
				srcs/memory/ft_chardup.c					\
				srcs/memory/ft_free_tab.c					\

# numeric
SRCS		+=	srcs/numeric/ft_nbrlen.c					\
				srcs/numeric/ft_convert_base.c				\
				srcs/numeric/ft_itoa.c						\
				srcs/numeric/ft_atol.c						\
				srcs/numeric/ft_uitoa.c						\
				srcs/numeric/ft_ltoa.c						\
				srcs/numeric/ft_ltoa_base.c					\
				srcs/numeric/ft_uitoa_base.c				\
				srcs/numeric/ft_itoa_width.c				\
				srcs/numeric/ft_pow.c						\
				srcs/numeric/ft_atoi.c						\
				srcs/numeric/ft_atoi_strict.c				\
				srcs/numeric/ft_atof.c						\
				srcs/numeric/ft_atoi_base.c					\
				srcs/numeric/ft_max_int.c					\
				srcs/numeric/ft_max_float.c					\
				srcs/numeric/ft_min_int.c					\
				srcs/numeric/ft_min_float.c					\

# string
SRCS		+=	srcs/string/ft_in_charset.c					\
				srcs/string/ft_is_from_charset.c			\
				srcs/string/ft_strlen.c						\
				srcs/string/ft_strdup.c						\
				srcs/string/ft_strndup.c					\
				srcs/string/ft_strcpy.c						\
				srcs/string/ft_strlcpy.c					\
				srcs/string/ft_strcat.c						\
				srcs/string/ft_strlcat.c					\
				srcs/string/ft_strcmp.c						\
				srcs/string/ft_strncmp_rev.c				\
				srcs/string/ft_strncmp.c					\
				srcs/string/ft_strchr.c						\
				srcs/string/ft_strrchr.c					\
				srcs/string/ft_strmap.c						\
				srcs/string/ft_strmapi.c					\
				srcs/string/ft_substr.c						\
				srcs/string/ft_split_set.c					\
				srcs/string/ft_strjoin.c					\
				srcs/string/ft_strjoin_sep.c				\
				srcs/string/ft_strjoin_free.c				\
				srcs/string/ft_strtrim.c					\
				srcs/string/ft_strstr.c						\
				srcs/string/ft_strnstr.c					\
				srcs/string/ft_isprint.c					\
				srcs/string/ft_isalpha.c					\
				srcs/string/ft_isdigit.c					\
				srcs/string/ft_issign.c						\
				srcs/string/ft_isalnum.c					\
				srcs/string/ft_isascii.c					\
				srcs/string/ft_toupper.c					\
				srcs/string/ft_tolower.c					\
				srcs/string/ft_split.c						\

# tabs
SRCS		+=	srcs/tabs/sort_int.c						\
				srcs/tabs/sort_str.c						\

# ft_printf
SRCS 		+= 	srcs/ft_printf/ft_printf.c					\
				srcs/ft_printf/ft_s_printf_utils.c			\
				srcs/ft_printf/ft_char.c					\
				srcs/ft_printf/ft_hex.c						\
				srcs/ft_printf/ft_integer.c					\
				srcs/ft_printf/ft_integer2.c				\
				srcs/ft_printf/ft_integer3.c				\
				srcs/ft_printf/ft_pointer.c					\
				srcs/ft_printf/ft_string.c					\
				srcs/ft_printf/ft_unsigned_int.c			\
				srcs/ft_printf/ft_percent.c					\
				srcs/ft_printf/ft_width.c					\
				srcs/ft_printf/ft_flags.c					\
				srcs/ft_printf/ft_atoi_no_sign.c			\

# get_next_line
SRCS		+=	srcs/gnl/get_next_line.c

###########################

OPTI = -Ofast #-O3

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
# .SILENT:

###########################COLOR
#----------------reset----------------#
NC = \033[0m

#-----------Regular Colors------------#
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[33;33m
BLUE = \033[0;34m
PURPLE = \033[35m
CYAN = \033[1;36m
WHITE = \033[0;37m

###########################ECHO

echoCL:
	echo "$(YELLOW)Compiling Libft$(NC)"
echoOK:
	echo "$(GREEN) OK$(NC)"
echoCS :
	echo "$(GREEN)===> Compilation Success$(NC)"
echoAR :
	echo "$(CYAN)===> Archiving Libft$(NC)$(GREEN) OK$(NC)\n"