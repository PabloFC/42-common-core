# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 11:04:59 by pafuente          #+#    #+#              #
#    Updated: 2025/03/24 11:44:12 by pafuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_NAME = client
SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRC)
$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC)

$(SERVER_NAME): $(SERVER_SRC)
$(CC) $(CFLAGS) -o $@ $(SERVER_SRC)

clean:
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

