NAME	=	libftprintf.a

SRC	=	helpers/char_helper.c\
		helpers/int_helper.c\
		helpers/low_hex_helper.c\
		helpers/percent_helper.c\
		helpers/pointer_helper.c\
		helpers/string_helper.c\
		helpers/unsigned_helper.c\
		helpers/up_hex_helper.c\
		utils.c\
		ft_printf.c

OBJ	=	$(SRC:.c=.o)

CC	=	clang
FLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $@ $^

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re\