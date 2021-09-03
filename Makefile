# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 14:38:46 by nrubin            #+#    #+#              #
#    Updated: 2021/09/03 15:27:54 by nrubin           ###   ########.fr        #
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

SRCBONUS =	bonus/helpers_bonus/char_helper_bonus.c\
			bonus/helpers_bonus/int_helper_bonus.c\
			bonus/helpers_bonus/low_hex_helper_bonus.c\
			bonus/helpers_bonus/percent_helper_bonus.c\
			bonus/helpers_bonus/pointer_helper_bonus.c\
			bonus/helpers_bonus/string_helper_bonus.c\
			bonus/helpers_bonus/unsigned_helper_bonus.c\
			bonus/helpers_bonus/up_hex_helper_bonus.c\
			bonus/utils_bonus/utils_bonus.c\
			bonus/utils_bonus/utils2_bonus.c\
			bonus/utils_bonus/utils3_bonus.c\
			bonus/utils_bonus/utils4_bonus.c\
			bonus/utils_bonus/utils5_bonus.c\
			bonus/parsing_bonus/parser_bonus.c\
			bonus/ft_printf_bonus.c

OBJ	=	$(SRC:.c=.o)

OBJBONUS =	$(SRCBONUS:.c=.o)

CC	=	clang
FLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

bonus:	$(OBJBONUS)
		ar rc $(NAME) $(OBJBONUS)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all make clean fclean re bonus
