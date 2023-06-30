# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:08:49 by ykerdel           #+#    #+#              #
#    Updated: 2023/01/25 15:10:54 by ykerdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=ft_printf.c \
	ft_printf_utils.c \
	ft_printf_uni.c \
	ft_printf_ptr.c \
	ft_printf_hex.c \
	ft_printf_khnishou.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
