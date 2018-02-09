/*
** EPITECH PROJECT, 2018
** button appli
** File description:
** world
*/

#include "my_world.h"

void selection_button_manager(window_t *window, button_t button)
{
	if (window->window_ui.tools_state.corner == sfTrue) {
		window->window_ui.tools_state.corner = sfFalse;
		change_button_message(button, "tiles");
	}
	else {
		window->window_ui.tools_state.corner = sfTrue;
		change_button_message(button, "corner");
	}
}

void button_load(map_node_t **map2d, window_t *window)
{
	load_new_map("data2", window);
}

void button_quit(map_node_t **map2d, window_t *window)
{
	save_map("auto_save", *window);
	exit(0);
}
