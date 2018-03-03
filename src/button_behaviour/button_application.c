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
	} else {
		window->window_ui.tools_state.corner = sfTrue;
		change_button_message(button, "corner");
	}
}

void button_save(map_node_t **map2d, window_t *window)
{
	if (window->window_ui.tools_state.save == sfFalse) {
		window->window_ui.tools_state.save = sfTrue;
		window->window_ui.tools_state.load = sfFalse;
	}
}

void button_load(map_node_t **map2d, window_t *window)
{
	if (window->window_ui.tools_state.load == sfFalse) {
		window->window_ui.tools_state.load = sfTrue;
		window->window_ui.tools_state.save = sfFalse;
	}
}

void button_quit(map_node_t **map2d, window_t *window)
{
	save_map("auto_save", *window);
	window->quit = sfTrue;
}
