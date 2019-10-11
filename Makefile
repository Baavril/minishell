# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/10/08 17:52:05 by baavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS		= -Wall -Werror -Wextra -MMD 

NAME		=	minishell

LIB_PATH	=	libft
LIB		=	libft.a

LIBS		= 	$(LIB_PATH)/$(LIB)

DIR_O		=	temporary

SRC_PATH	=	srcs
SOURCES 	=	main.c \
			env_settings.c \
			env_builtins.c \
			setenv.c \
			unsetenv.c \
			env_tab_creation.c \
			env_lst_creation.c \
			expansion_handler.c \
			expansion_settings.c \
			expansion_tokens.c \
			launcher.c \
			crisis_room.c \
			other_builtins_commands.c \
			cd_handler.c \
			cd_path_handler.c \
			execute_commands.c \
			execute_commands2.c \
			manage_home.c \

SRCS    	=   $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS    	=   $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
DEPS    	=   $(addprefix $(DIR_O)/,$(SOURCES:.c=.d))

HDR_PATH	=	includes
HEADERS		=	minishell.h
HDR			=	$(addprefix $(HDR_PATH)/,$(HEADERS))

CLEAN		=	clean

all     :   $(NAME)

$(LIB)  :
	@make -C $(LIB_PATH)

$(NAME) : $(LIB) $(OBJS) $(HDR) Makefile
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "minishell has been successfully created."

$(DIR_O)/%.o: $(SRC_PATH)/%.c
	@mkdir -p temporary
	$(CC) $(CFLAGS) -I $(HDR_PATH) -o $@ -c $<

clean   :
	@rm -rf $(DIR_O)
	@make clean -C $(LIB_PATH)
	@echo "All .o files have been deleted."

fclean  :   clean
	@rm -rf $(NAME)
	@rm -rf $(LIBS)
	@echo "minishell and libft.a have been deleted."

re      :   fclean all

.PHONY: all clean fclean re

-include $(DEPS)
