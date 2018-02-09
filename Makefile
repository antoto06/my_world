##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME		=	my_world

SRC_DISPLAY	=	src/display/create_vertex.c \
			src/display/display_vertex.c \
			src/display/display_button.c

SRC_GENE	=	src/generation/generate_2D_map.c \
			src/generation/generate_texture.c \
			src/generation/update_map.c \
			src/generation/teraformation/tool_elevation.c \
			src/generation/teraformation/tool_dig.c

SRC_MATHS	=	src/maths/iso_projection.c

SRC_STRUCT	=	src/structures/create_window.c \
			src/structures/create_button.c \
			src/structures/create_map_node.c \
			src/structures/create_ui.c

SRC_EVENT	=	src/event_handler/event_manager.c \
			src/event_handler/click_button.c \
			src/event_handler/button_manager.c \
			src/event_handler/hover_manager.c

SRC_BUTTON	=	src/button_behaviour/button_translate.c \
			src/button_behaviour/button_application.c \
			src/button_behaviour/button_tools.c

SRC_PARSER	=	src/parser/parser.c \
			src/parser/reading.c

SRC_ERROR	=	src/error/error_window.c

SRC_SAVE	=	src/save_load/save.c

SRC		=	src/main.c

OBJ	=	$(SRC:.c=.o) $(SRC_DISPLAY:.c=.o) $(SRC_GENE:.c=.o) \
		$(SRC_MATHS:.c=.o) $(SRC_STRUCT:.c=.o) $(SRC_EVENT:.c=.o) \
		$(SRC_BUTTON:.c=.o) $(SRC_PARSER:.c=.o) $(SRC_ERROR:.c=.o) \
		$(SRC_SAVE:.c=.o)

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include -g3

LDFLAG	=	-L./lib/my -lmy -L./lib/gnl -lgnl

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C lib/my
		make -C lib/gnl
		cc -o $(NAME) $(OBJ) $(LDFLAG) -lm -lc_graph_prog -g3
clean	:
		make -C lib/my clean
		make -C lib/gnl clean
		rm -f $(NAME)

fclean	:	clean
		make -C lib/gnl fclean
		make -C lib/my fclean
		rm -f $(OBJ)

re	:	fclean all
