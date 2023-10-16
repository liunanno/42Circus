# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 18:58:38 by nliu              #+#    #+#              #
#    Updated: 2023/10/16 18:58:41 by nliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minitalk.h

SERVER_SRCS = server.c utils.c
CLIENT_SRCS = client.c utils.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEL = rm -rf

all: server client

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o client

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o server

%.o:%.c $(NAME_H)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DEL) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:clean
	$(DEL) client server

re : clean client server