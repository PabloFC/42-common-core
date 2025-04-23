# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 12:28:17 by pafuente          #+#    #+#              #
#    Updated: 2025/04/23 11:22:19 by pafuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/main.c \
       src/parsing/parse_args.c \
       src/utils/stack_utils.c \
       src/sorting/small_sort.c \
       src/sorting/radix_sort.c \
       src/sorting/sort_utils.c \
       src/operations/push.c \
       src/operations/swap.c \
       src/operations/rotate.c \
       src/operations/reverse_rotate.c \
       src/utils/error_handling.c \
       src/utils/ft_isdigit.c \
       src/utils/ft_printf.c \
       src/utils/utils.c
      

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re