SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = server client

all: $(NAME)

bonus: $(NAME)

server: server.o libft ft_printf
	$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

client: client.o libft ft_printf
	$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

ft_printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C ft_printf clean
	
fclean: clean
	rm -f $(NAME) libft/libft.a 
	rm -f $(NAME) ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus libft ft_printf clean fclean re