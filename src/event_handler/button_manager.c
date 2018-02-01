/*
** EPITECH PROJECT, 2018
** button_manager.c
** File description:
** world
*/

#include "my_world.h"

void button_manager(sfMouseButtonEvent mouse_event, window_t *window,
		map_node_t **map2d)
{
	button_t *buttons_tmp = window->window_ui.button_translate;

	if (button_is_clicked(buttons_tmp[0], mouse_event) == sfTrue) {
		button_translate(map2d, -1, 0);
	}
	if (button_is_clicked(buttons_tmp[1], mouse_event) == sfTrue) {
		button_translate(map2d, 1, 0);
	}
	if (button_is_clicked(buttons_tmp[2], mouse_event) == sfTrue) {
		button_translate(map2d, 0, 1);
	}
	if (button_is_clicked(buttons_tmp[3], mouse_event) == sfTrue) {
		button_translate(map2d, 0, -1);
	}
}
