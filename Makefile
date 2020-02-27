# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/02/27 17:52:01 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#			VARIABLES				#

NAME =		miniRT

LIB_DIR =	lib/libft lib/minilibx
OBJ_DIR =	obj/
SRC_DIR =	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) lib/libft/includes lib/minilibx/

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

LIB		=	ft mlx

SRC 	=	
OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
HEADERS = 	$(foreach headers, $(INC_DIR), $(headers)%.h)

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)



#	COMPILATION		#

CC = 		gcc

CFLAG = 	-Wall -Werror -Wextra -fsanitize=address -g
IFLAG = 	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG  =	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )


#	FONCTIONS	#


all:		$(NAME)

$(LIB):
			make -C $(LIB_DIR) all

$(OBJ_DIR)%.o: %.c $(HEADERS)
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
