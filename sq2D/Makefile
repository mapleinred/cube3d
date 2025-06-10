# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 13:26:08 by xzhang            #+#    #+#              #
#    Updated: 2024/01/03 14:10:58 by xzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
RED    = '\033[1;31m'
GREEN  = '\033[1;32m'
BLUE   = '\033[1;34m'
CYAN   = '\033[0;36m'

#Variables
NAME   = sq2d

SRCS = atod.c sq2d.c
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
MAIN = srcs/sq2d.c

SRC_DIR = srcs/
OBJ_DIR = objs/

HEADER = -Iinclude

LIBFT = ./libs/libft/libft.a
LIB_DIR = libs/libft

MLX = ./libs/minilibx-linux/libmlx.a
MLX_DIR = libs/minilibx-linux


CC     = gcc
RM     = rm -rf
CFLAGS = -Wall -Wextra -Werror -g



#Main targets
all: ${NAME}

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) -lXext -lX11 -lm
	@echo $(CYAN)"sq2d made!"

$(LIBFT):
	make -C ./libs/libft

$(MLX):
	make -C ./libs/minilibx-linux

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

leaks :
	@valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-limit=no --tool=memcheck -s ./fractol $(ARGS)

bleaks:
	./push_swap $(ARGS) | valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-limit=no --tool=memcheck -s ./fractol $(ARGS)

clean:
	make clean -C ./$(LIB_DIR)
	make clean -C ./$(MLX_DIR)
	${RM} $(OBJ_DIR)

fclean: clean
	make fclean -C ./$(LIB_DIR)
	make clean -C ./$(MLX_DIR)
	${RM} $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus
