# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sardomin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 18:57:21 by sardomin          #+#    #+#              #
#    Updated: 2025/03/21 18:57:24 by sardomin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc 

FLAGS = -Wall -Wextra -Werror -g -I minilibx-linux

SRC = main.c utils.c utils2.c utils3.c initializer.c\
 keyboard_mouse_events.c draw_fractol.c draw_fractol2.c ft_atof.c

OBJ= $(SRC:.c=.o)

MLX_PATH = minilibx-linux
MLX = $(MLX_PATH)/libmlx.a



INCLUDE = fractol.h

all: $(NAME)

$(NAME): $(OBJ) Makefile $(INCLUDE)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) -L$(MLX_PATH) -lmlx -lX11 -lXext
 	
%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

