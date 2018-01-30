##
## EPITECH PROJECT, 2017
## libmy
## File description:
## library my
##

SRC	=	my_put_nbr.c \
		my_getnbr.c \
		my_putchar.c \
		my_strlen.c \
		my_strcat_malloc.c \
		my_putstr.c \
		my_putstr_err.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./

LIB_NAME=	libmy.a

all:	$(LIB_NAME)

$(LIB_NAME):
	gcc -c $(SRC) -I./
	ar rc $(LIB_NAME) *.o
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_NAME)

re:	fclean all
