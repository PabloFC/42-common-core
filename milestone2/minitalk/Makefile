# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 11:04:59 by pafuente          #+#    #+#              #
#    Updated: 2025/03/25 13:32:22 by pafuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

SRCS_SERVER = ./server.c
SRCS_CLIENT = ./client.c

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(SRCS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_SERVER) $(SRCS_SERVER) $(LIBFT)

$(NAME_CLIENT): $(SRCS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
