# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/02/26 13:10:34 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#			VARIABLES				#

NAME =		miniRT

LIB_DIR =	lib/libft lib/minilibx
OBJ_DIR =	obj/
SRC_DIR =	$(shell find src -type d)
INC_DIR = 	$(shell find includes -type d) lib/libft/includes lib/mlx/elcapitan

LIB		=	ft 

SRC 	=	ft_printf.c 		\
			ft_printf_utils.c	\
			flags_collect.c 	\
			type_args.c			\
			init_and_clean.c 	\
			conversion.c 		\
			dispatch.c 			\
			make_options.c		\
			print_character.c 	\
			print_number.c 		\
			print_string.c 		\
			unicode.c

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

#	COMPILATION		#

CC = 		gcc

CFLAG = 	-Wall -Werror -Wextra 
IFLAG = 	-I src/ -I libft/	
LFLAG  =	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )


#	FONCTIONS	#


all:		$(NAME)

$(LIB):
			make -C $(LIB_DIR) all

$(OBJ_DIR)%.o: %.c src/ft_printf.h
			mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<

$(NAME): 	$(LIB) $(OBJ)
			cp $(LIB_DIR)/libft.a $@
			ar rcs $(NAME) $(OBJ)

bonus : all

# 	CLEAN	#


clean:
			rm -rf $(OBJ_DIR)
			make -C $(LIB_DIR) clean

fclean: clean
			rm -f $(NAME)
			make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean flcean re
