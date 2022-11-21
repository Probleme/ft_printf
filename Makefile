# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 00:43:19 by ataouaf           #+#    #+#              #
#    Updated: 2022/11/21 01:18:53 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
cc = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	  ft_printf.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_itoa.c \
	  ft_puthex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	ar crsu $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re