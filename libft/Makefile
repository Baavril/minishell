# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 19:07:58 by baavril           #+#    #+#              #
#    Updated: 2019/10/07 20:09:11 by baavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCFILE	= ft_swap.c\
		  ft_btw.c\
		  ft_print_list.c\
		  ft_lstfree.c\
		  ft_lstfreeone.c\
		  ft_bzero.c\
		  ft_memset.c\
		  ft_memcpy.c\
		  ft_memccpy.c\
		  ft_memmove.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strlen.c\
		  ft_strdup.c\
		  ft_strndup.c\
		  ft_strcpy.c\
		  ft_strncpy.c\
		  ft_strcat.c\
		  ft_strncat.c\
		  ft_strlcat.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strstr.c\
		  ft_strnstr.c\
		  ft_strspn.c\
		  ft_strjoinfree.c\
		  ft_strsubfree.c\
		  ft_strcspn.c\
		  ft_strcmp.c\
		  ft_strncmp.c\
		  ft_atoi.c\
		  ft_itoa.c\
		  ft_pow.c\
		  ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_isin.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_memalloc.c\
		  ft_memdel.c\
		  ft_strnew.c\
		  ft_str_to_wordtab.c\
		  ft_strdel.c\
		  ft_strclr.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strequ.c\
		  ft_strnequ.c\
		  ft_strsub.c\
		  ft_strjoin.c\
		  ft_strappend.c\
		  ft_strappend_back.c\
		  ft_strtrim.c\
		  ft_strrev.c\
		  ft_strsplit.c\
		  ft_putchar.c\
		  ft_putchar_fd.c\
		  ft_putstr.c\
		  ft_putstr_fd.c\
		  ft_putendl.c\
		  ft_putnendl.c\
		  ft_putendl_fd.c\
		  ft_putnbr.c\
		  ft_putnbr_fd.c\
		  ft_putnbr_base.c\
		  ft_putnbr_long.c\
		  ft_putnbr_base_long.c\
		  ft_lstadd.c\
		  ft_lstdel.c\
		  ft_lstdelone.c\
		  ft_lstnew.c\
		  ft_lstmap.c\
		  ft_lstiter.c\
		  ft_lstadd_back.c\
		  get_next_line.c\
		  ft_print_wordtab.c\

SRCDIR	= ./
SRC		= $(addprefix $(SRCDIR),$(SRCFILE))
HDR 	= .
OBJ 	= $(SRCFILE:.c=.o)

NAME 	= libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDR)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
