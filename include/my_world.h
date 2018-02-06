/*
** EPITECH PROJECT, 2018
** header
** File description:
** header
*/

#ifndef MY_WORLD_H
#define MY_WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <math.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <fcntl.h>

#define ANGLE_X 35
#define ANGLE_Y 25.264
#define SCALING_X 64
#define SCALING_Y 64
#define SCALING_Z 64

#define BUTTON_GREEN "ressources/UI/button_green.png"
#define BUTTON_GREEN_BURN "ressources/UI/button_green_burn.png"
#define HOVER_SHAPE "ressources/UI/hover_vertex.png"
#define CONVEX_SHAPE "ressources/UI/convex_txtr_base.png"
#define FONT1 "ressources/Font/Font1.otf"
#define TXTR_GRASS "ressources/UI/grass-texture.jpg"
#define TXTR_DIRT "ressources/UI/brown.png"
#define TXTR_ROCK_BURN "ressources/UI/rock_texture_burn.png"
#define TXTR_ROCK "ressources/UI/rock_texture.jpg"

typedef struct input_map_s {
	int **map;
	int len_x;
	int len_y;
} input_map_t;

typedef struct map_node_s {
	input_map_t input_map;
	sfVector2f iso_point;
	sfConvexShape *node_shape;
	sfTexture *node_txtr;
	sfVector2f *convex_points;
	sfCircleShape *hover_shape;
	sfTexture *hover_shape_txtr;
	sfBool hover_visible;
} map_node_t;

typedef struct button_s {
	sfRectangleShape *shape;
	sfTexture *txtr;
	sfVector2f size;
	sfVector2f pos;
	sfText *message;
	sfFont *font;
} button_t;

typedef struct tools_state_s {
	sfBool elevate;
	sfBool dig;
} tools_state_t;

typedef struct ui_s {
	button_t *button_translate;
	button_t *button_application;
	button_t *button_tools;
	tools_state_t tools_state;
} ui_t;

typedef struct window_s {
	sfVector2u size;
	sfRenderWindow *m_window;
	sfEvent event;
	ui_t window_ui;
	sfBool map_visible;
	map_node_t **stock_map2d;
} window_t;

sfVector2f project_iso_point(int x, int y, int z);
window_t create_window(int, int);
map_node_t create_map_node(int, int, int, window_t);
map_node_t **create_2d_map(input_map_t map3d, window_t);
int display_vertex(window_t *, map_node_t **);
void display_point(int, int, sfRenderWindow *, map_node_t **);
sfVertexArray *create_line(sfVector2f *, sfVector2f *);
sfVector2f quick_projection_iso_point(sfVector2f, int);
button_t create_button(sfVector2f position, char *msg);
ui_t create_ui();
void button_translate(map_node_t **, int, int);
void display_button_translate(window_t window, button_t *buttons);
int check_error(int ac, char **av);
void button_manager(sfMouseButtonEvent mouse_event, window_t *, map_node_t **);
sfBool button_is_clicked(button_t button, sfMouseButtonEvent click_pos);
void analyse_event(window_t *window, map_node_t **map2d);
void hover_manager(sfMouseMoveEvent mouse_evt, map_node_t **);
void generate_texture(map_node_t **map2d);
void display_button_translate(window_t window, button_t *buttons);
window_t create_window_err(int, char **);
input_map_t my_rd(char *str);
input_map_t my_str_to_int_array(char *);
sfVector2u get_hovered_point(map_node_t **map2d);

#endif
