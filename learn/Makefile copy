# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/02/28 14:27:54 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		miniRT

LIB_DIR =	lib/libft lib/NOT_MLX
SRC_DIR =	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) lib/libft/includes lib/minilibx/ lib/NOT_MLX/incs
OBJ_DIR =	obj/

LIB		=	ft mlx
SRC 	=	
OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
HEADERS = 	$(foreach headers, $(INC_DIR), $(headers)%.h)
FRAMEWORK = AppKit OpenGL

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)


# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC 		=	gcc

CFLAG 	= 	-Wall -Werror -Wextra -fsanitize=address -g
IFLAG 	= 	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG 	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )
LFLAG 	+= 	$(foreach framework, $(FRAMEWORK), -framework $(framework) )


# ----------------- #
#	  FONCTIONS		#
# ----------------- #

all:		$(NAME)


$(OBJ_DIR)%.o: %.c $(HEADERS)
			mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<

$(NAME): 	install $(LIB) $(OBJ)
			$(CC) $(CFLAG) $(IFLAG) $(LFLAG) $(OBJ) -o $@

install :
			make -C lib/libft
			make -C lib/NOT_MLX

re-install :
			@make -C lib/libft re
			make -C lib/NOT_MLX re

bonus : all

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"


# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			rm -rf $(OBJ_DIR)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
