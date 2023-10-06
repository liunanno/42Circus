NAME = ciao
SRC = client.c minitalk.c
OBJ = client.o minitalk.o

all: client server

client:
	gcc $(SRC) -c 
	gcc $(OBJ) -o $(NAME)

server:
	gcc $(SRC) -c 
	gcc $(OBJ) -o $(NAME)

clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)