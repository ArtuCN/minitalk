CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

CLIENT := client
SERVER := server

SRC_SERVER := server.c utils.c
SRC_CLIENT := client.c utils.c

INCLUDES := -I. -Ilibft

LIBFT := ./libft/libft.a
LIBFT_PATH := ./libft

all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_PATH)
$(SERVER): $(LIBFT) $(SRC_SERVER)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER) $(LIBFT) -o $@
$(CLIENT): $(LIBFT) $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT) $(LIBFT) -o $@


clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(SRC_SERVER:.c=.o) $(SRC_CLIENT:.c=.o)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all
