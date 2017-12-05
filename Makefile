# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:54:33 by tperraut          #+#    #+#              #
#*   Updated: 2016/07/06 14:08:25 by tperraut         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

##########
# TARGET #
##########

NAME = fdf

############
# COMPILER #
############

CC = clang
CFLAGS = -O3 -Werror -Wall -Wextra

#######
# LIB #
#######

LIB = -lft
LIB_DIR = ./libft
LIB_INC = -I $(LIB_DIR)/include

#######
# MLX #
#######

SYS = linux
FRAMEWORK =
ifneq (, $(findstring apple, $(shell $(CC) -dumpmachine)))
	SYS = mac
	FRAMEWORK = -framework OpenGL -framework AppKit
endif
MLX = -lmlx $(FRAMEWORK)
MLX_DIR = ./mlx-$(SYS)
MLX_INC_DIR = $(MLX_DIR)/include/
MLX_INC_NAME = mlx.h
MLX_INC = -I $(MLX_INC_DIR)
MLX_INCLUDE = $(addprefix $(MLX_INC_DIR), $(MLX_INC_NAME))

#######
# X11 #
#######

ifeq ($(SYS), linux)
X11_LIB = -lX11 -lXext
endif

########
# MATH #
########

MATH = -lm

##########
# HEADER #
##########

INC_DIR = ./include/
INC_NAME = \
		fdf.h \
		get_next_line.h \
		key.h
INCLUDE = $(addprefix $(INC_DIR), $(INC_NAME))
INC = -I $(INC_DIR)

##########
# SOURCE #
##########

SRC_DIR = ./src/
SRC_NAME = \
	fill_line.c \
	ft_point.c \
	ft_expose.c \
	get_next_line.c \
	parser.c \
	error.c \
	finish.c \
	manage_mouse.c \
	manage_key.c \
	init_map.c \
	new_img_data.c \
	print_map.c \
	free_map.c \
	draw.c \
	main.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

##########
# OBJECT #
##########

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

#########
# RULES #
#########

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $@ \
		$(OBJ) \
		$(INC) \
		$(LIB_INC) -L $(LIB_DIR) $(LIB) \
		$(MLX_INC) -L $(MLX_DIR) $(MLX) \
		$(X11_LIB) \
		$(MATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE) $(MLX_INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(LIB_INC) $(INC) $(MLX_INC)

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
