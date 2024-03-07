# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 21:19:03 by gabpicci          #+#    #+#              #
#    Updated: 2024/03/06 23:50:10 by gabpicci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft.a

NXT = nxt.a

#PRINTF = libftprintf.a

LIBMLX = ./.minilibx-linux/libmlx_Linux.a ./.minilibx-linux/libmlx.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

LFLAGS = -L $(LIBMLX) $(LIBFT)

RM = rm -f

AR = ar -rsc

SRC = teste_wind.c map_check.c utils.c maze_solver.c error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3  -c $< -o $@

$(NAME): $(OBJ)
	@make -C ./libft 
	@make -C ./.minilibx-linux
	@mv ./libft/$(LIBFT) . 
	$(CC) $(OBJ) -L.minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) libft.a 

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft

	@make clean -C ./.minilibx-linux


fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all