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
	if (button_is_clicked(window->window_ui.button_translate,
			mouse_event) == sfTrue) {
		button_translate(map2d, -1, 0);
	}
}
