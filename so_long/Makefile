# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 19:10:22 by nliu              #+#    #+#              #
#    Updated: 2023/11/03 20:21:18 by nliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -o ./so_long -g -framework OpenGL -framework AppKit -lmlx
RM = @rm -rf
SRCS = $(wildcard ./program/*.c)
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(OBJS) $(FLAGS)

fclean:
	$(RM)  so_long so_long.dSYM
	$(RM) ./program/*.o ./program/program
	$(RM) ./minilibx/*.o

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

norm:
	norminette $(shell find ./program/ -name "*.c")

re: fclean all

.PHONY: re