# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 13:26:08 by xzhang            #+#    #+#              #
#    Updated: 2024/08/19 17:19:03 by xzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
RED    = '\033[1;31m'
GREEN  = '\033[1;32m'
BLUE   = '\033[1;34m'
CYAN   = '\033[0;36m'

#Variables
NAME = cub3D

SRCS = 	cub3d.c draw.c drawray.c free.c init.c keyhook.c linecheck.c load.c\
		mapcheck.c mapline.c minimap.c mlx.c texture.c utils.c drawray3d.c
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP	= $(OBJS:.o=.d)
MAIN = srcs/cub3d.c

SRC_DIR = srcs/
OBJ_DIR = objs/

HEADER = -Iinclude

LIBFT = ./libs/libft/libft.a
LIB_DIR = libs/libft

MLX = ./libs/minilibx-linux/libmlx.a
MLX_DIR = libs/minilibx-linux



CC     = gcc
RM     = rm -rf
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP

#Main targets
all: ${NAME}

-include $(DEP)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) -lXext -lX11 -lm
	@echo $(CYAN)"cub3D made!"

$(LIBFT):
	@make -C ./libs/libft

$(MLX):
	@make -C ./libs/minilibx-linux

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C ./$(LIB_DIR)
	@make clean -C ./$(MLX_DIR)
	@${RM} $(OBJ_DIR) $(DEP)

fclean: clean
	@make fclean -C ./$(LIB_DIR)
	@make clean -C ./$(MLX_DIR)
	@${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
