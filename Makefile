##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME		=	my_world

SRC_DISPLAY	=	src/display/create_vertex.c \
			src/display/display_vertex.c

SRC_GENE	=	src/generation/generate_2D_map.c

SRC_MATHS	=	src/maths/iso_projection.c

SRC		=	src/main.c

OBJ	=	$(SRC:.c=.o) $(SRC_DISPLAY:.c=.o) $(SRC_GENE:.c=.o) \
		$(SRC_MATHS:.c=.o)

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

LDFLAG	=	-L./lib/my -lmy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C lib/my
		cc -o $(NAME) $(OBJ) $(LDFLAG) -lm -lc_graph_prog
clean	:
		make -C lib/my clean
		rm -f $(NAME)

fclean	:	clean
		make -C lib/my fclean
		rm -f $(OBJ)

re	:	fclean all
