CC = gcc
FLAGS = -o ./so_long -g -framework OpenGL -framework AppKit -lmlx
RM = @rm -rf

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all:
	@echo $(B)Game Starting...
	$(CC) ./program/*.c $(FLAGS)

fclean:
	$(RM)  so_long so_long.dSYM
	$(RM) ./program/*.o ./program/program
	$(RM) ./minilibx/*.o

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

norm:
	@echo $(B)[--NORMINETTE SUCCES %100 CLEAN CODE...]$(B)
	norminette $(shell find ./program/ -name "*.c")

.PHONY: re
