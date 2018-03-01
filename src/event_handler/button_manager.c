/*
** EPITECH PROJECT, 2018
** button_manager.c
** File description:
** world
*/

#include "my_world.h"

void translate_button_manager(sfMouseButtonEvent mouse_event, window_t *window,
	map_node_t **map2d)
{
	button_t *buttons_tmp = window->window_ui.button_translate;

	if (button_is_clicked(buttons_tmp[0], mouse_event) == sfTrue)
		button_translate(map2d, -1, 0);
	if (button_is_clicked(buttons_tmp[1], mouse_event) == sfTrue)
		button_translate(map2d, 1, 0);
	if (button_is_clicked(buttons_tmp[2], mouse_event) == sfTrue)
		button_translate(map2d, 0, 1);
	if (button_is_clicked(buttons_tmp[3], mouse_event) == sfTrue)
		button_translate(map2d, 0, -1);
	if (button_is_clicked(buttons_tmp[4], mouse_event) == sfTrue)
		button_zoom(map2d, 2, window);
	if (button_is_clicked(buttons_tmp[5], mouse_event) == sfTrue)
		button_zoom(map2d, -2, window);
}

void application_button_manager(sfMouseButtonEvent mouse_event, window_t *window,
		map_node_t **map2d)
{
	button_t *buttons_tmp = window->window_ui.button_application;

	if (button_is_clicked(buttons_tmp[0], mouse_event) == sfTrue) {
		button_load(map2d, window);
	}
	if (button_is_clicked(buttons_tmp[1], mouse_event) == sfTrue) {
		button_quit(map2d, window);
	}
	if (button_is_clicked(buttons_tmp[2], mouse_event) == sfTrue) {
		selection_button_manager(window, buttons_tmp[2]);
	}
	if (button_is_clicked(buttons_tmp[3], mouse_event) == sfTrue) {
		button_save(map2d, window);
	}
}

void button_manager(sfMouseButtonEvent mouse_event, window_t *window,
		map_node_t **map2d)
{
	translate_button_manager(mouse_event, window, map2d);
	application_button_manager(mouse_event, window, map2d);
	tools_button_manager(mouse_event, window, map2d);
	button_text_box(window, mouse_event);
}
