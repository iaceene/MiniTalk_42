SRC_CLIENT = ./mandatory/src_client/main.c ./mandatory/src_client/cli_utiles.c
SRC_SERVER = ./mandatory/src_server/main.c ./mandatory/src_server/ft_putnbr.c ./mandatory/src_server/srv_utiles.c
INCLUDES = ./mandatory/src_client/client.h ./mandatory/src_server/server.h

SRC_CLIENT_BONUS = ./bonus/src_client/main_bonus.c ./bonus/src_client/cli_utiles_bonus.c
SRC_SERVER_BONUS = ./bonus/src_server/main_bonus.c ./bonus/src_server/ft_putnbr_bonus.c ./bonus/src_server/srv_utiles_bonus.c
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

# Default target
all: $(CLI_NAME) $(SER_NAME)

# Bonus target
bonus: $(CLI_NAME_BONUS) $(SER_NAME_BONUS)

# Client and Server (mandatory) compilation
$(CLI_NAME): $(OBJ_CLIENT)
	cc $(CFLAGS) $(OBJ_CLIENT) -o $(CLI_NAME)

$(SER_NAME): $(OBJ_SERVER)
	cc $(CFLAGS) $(OBJ_SERVER) -o $(SER_NAME)

# Client and Server (bonus) compilation
$(CLI_NAME_BONUS): $(OBJ_CLIENT_BONUS)
	cc $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(CLI_NAME_BONUS)

$(SER_NAME_BONUS): $(OBJ_SERVER_BONUS)
	cc $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(SER_NAME_BONUS)

# Object files rule (mandatory and bonus variants)
%.o: %.c $(INCLUDES)
	cc $(CFLAGS) -c $< -o $@

# Bonus object files rule (separate from mandatory objects)
%.o: %.c $(INCLUDES_BONUS)
	cc $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

# Full clean (removes object files and binaries)
fclean: clean
	rm -f $(CLI_NAME) $(SER_NAME) $(CLI_NAME_BONUS) $(SER_NAME_BONUS)

# Rebuild everything
re: fclean all

.PHONY: clean fclean re bonus
