SRC_CLIENT = ./src/src_client/main.c ./src/src_client/cli_utiles.c
SRC_SERVER = ./src/src_server/main.c ./src/src_server/ft_putnbr.c ./src/src_server/srv_utiles.c
INCLUDES = ./src/src_client/client.h ./src/src_server/server.h

SRC_CLIENT_BONUS = ./bonus/src_client/main_bonus.c ./bonus/src_client/cli_utiles_bonus.c
SRC_SERVER_BONUS = ./bonus/src_server/main_bonus.c ./bonus/src_server/ft_putnbr_bonus.c ./bonus/src_server/srv_utiles_bonus.c ./bonus/src_server/buffer_bonus.c
INCLUDES_BONUS = ./bonus/src_client/client_bonus.h ./bonus/src_server/server_bonus.h

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

CLI_NAME = client
SER_NAME = server

CLI_NAME_BONUS = client_bonus
SER_NAME_BONUS = server_bonus

CFLAGS = -Wall -Wextra -Werror

all: $(CLI_NAME) $(SER_NAME)

bonus: $(CLI_NAME_BONUS) $(SER_NAME_BONUS)

$(CLI_NAME): $(OBJ_CLIENT)
	cc $(CFLAGS) $(OBJ_CLIENT) -o $(CLI_NAME)

$(SER_NAME): $(OBJ_SERVER)
	cc $(CFLAGS) $(OBJ_SERVER) -o $(SER_NAME)

$(CLI_NAME_BONUS): $(OBJ_CLIENT_BONUS)
	cc $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(CLI_NAME_BONUS)

$(SER_NAME_BONUS): $(OBJ_SERVER_BONUS)
	cc $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(SER_NAME_BONUS)

%.o: %.c $(INCLUDES)
	cc $(CFLAGS) -c $< -o $@

%.o: %.c $(INCLUDES_BONUS)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
	rm -f $(CLI_NAME) $(SER_NAME) $(CLI_NAME_BONUS) $(SER_NAME_BONUS)

re: fclean all