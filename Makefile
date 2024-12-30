SRC_CLIENT = ./src_client/main.c ./src_client/cli_utiles.c
SRC_SERVER = ./src_server/main.c ./src_server/ft_putnbr.c
INCLUD = ./src_client/client.h ./src_server/server.h

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CLI_NAME = client
SER_NAME = server

CFLAGS = -Wall -Wextra -Werror

all: $(CLI_NAME) $(SER_NAME)

$(CLI_NAME): $(OBJ_CLIENT)
	cc $(CFLAGS) $(OBJ_CLIENT) -o $(CLI_NAME)

$(SER_NAME): $(OBJ_SERVER)
	cc $(CFLAGS) $(OBJ_SERVER) -o $(SER_NAME)

%.o: %.c $(INCLUD)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(CLI_NAME) $(SER_NAME)

re: fclean all

.PHONY: clean fclean re
