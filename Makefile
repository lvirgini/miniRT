# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2021/03/17 14:45:32 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		minirt

LIB_DIR =	lib/libft/	lib/minilibx-linux/ 
SRC_DIR =	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) lib/libft/includes lib/minilibx-linux
OBJ_DIR =	obj/

LIB		=	ft mlx m GLEW glfw GL
SRC 	=	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ 	=	$(addprefix $(OBJ_DIR),$(SRC:%.c=%.o))
HEADERS = 	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))
#FRAMEWORK = AppKit OpenGL

vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)


# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC 		=	clang

CFLAG 	= 	-Wall -Wextra -Wpedantic -g  -fsanitize=leak
IFLAG 	= 	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG 	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )
#LFLAG 	+= 	$(foreach framework, $(FRAMEWORK), -framework $(framework) )

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

all:		$(NAME)


$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 

$(NAME): 	install $(OBJ)
			$(CC) $(CFLAG) $(IFLAG) $(OBJ) $(LFLAG)-o $@ -lX11 -lXext -lXdamage -lXfixes -lXtst -lm -lbsd


install :
			@make -C lib/libft
			@make -C lib/minilibx-linux

re-install :
			@make -C lib/libft re
			@make -C lib/minilibx-linux re
				
bonus :  all

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
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
