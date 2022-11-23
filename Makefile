# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 12:41:02 by ataouaf           #+#    #+#              #
#    Updated: 2022/11/23 15:21:10 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = print_c_s.c print_i_d_u.c print_p_x.c ft_printf.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re