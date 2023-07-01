# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 12:11:58 by ykerdel           #+#    #+#              #
#    Updated: 2023/07/01 11:49:11 by ykerdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		philosophers
CC				=		cc
AR				=		ar rcs
RM				=		rm -rf
CFLAGS			=		-Wall -Wextra -Werror -Ofast
LIBFT_PATH		=		libs/libft/libft.a
FT_PRINTF_PATH	=		libs/ft_printf/libftprintf.a

SRC			=	main.c	./src/actions.c	./src/check.c	./src/exit.c	\
				./src/init.c	./src/time.c

OBJ			=	${SRC:.c=.o}

$(NAME) : $(OBJ)
	@echo "----- Making libft -----"
	cd libs/libft && make
	@echo "----- Making ft_printf -----"
	cd libs/ft_printf && make
	@echo "----- Compiling philosophers -----"
	${CC} ${CFLGS} ${SRC} -o ${NAME}  ${LIBFT_PATH} ${FT_PRINTF_PATH}
	clear
	@echo "\033[31m	------------------***༺ (\033[31m\033[32mPhilosophers Compiled!\033[31m)༻***------------------\n\033[0m"

all: ${NAME}

clean:
	cd libs/libft && make clean
	cd libs/ft_printf && make clean
	rm -f ${OBJ}
	clear

fclean: clean
	cd libs/libft && make fclean
	cd libs/ft_printf && make fclean
	rm -f ${NAME}
	clear
	
re: fclean all

.PHONY: all install clean fclean re
