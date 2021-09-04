# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 14:38:46 by nrubin            #+#    #+#              #
#    Updated: 2021/09/04 16:18:18 by nrubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC	=	helpers/char_helper.c\
		helpers/int_helper.c\
		helpers/low_hex_helper.c\
		helpers/percent_helper.c\
		helpers/pointer_helper.c\
		helpers/string_helper.c\
		helpers/unsigned_helper.c\
		helpers/up_hex_helper.c\
		utils/utils.c\
		utils/utils2.c\
		utils/utils3.c\
		utils/utils4.c\
		utils/utils5.c\
		parsing/parser.c\
		ft_printf.c

OBJ	=	$(SRC:.c=.o)

CC	=	clang
FLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all make clean fclean re
