/*
** EPITECH PROJECT, 2018
** background
** File description:
** world
*/

#include "my_world.h"

void display_background(window_t window)
{
	sfRenderWindow_drawRectangleShape(window.m_window,
			window.background, sfFalse);
}

void display_tree(window_t *window)
{
	display_background(*window);
	display_vertex(window, window->stock_map2d);
	display_button_translate(*window,
		window->window_ui.button_translate);
	display_button_application(*window,
		window->window_ui.button_application);
	display_button_tools(*window, window->window_ui.button_tools);
	display_buble_box(window->buble_box, *window);
	if (window->window_ui.tools_state.save == sfTrue)
		display_text_box(window->window_ui.input_box, *window);
	if (window->window_ui.tools_state.load == sfTrue)
		display_text_box(window->window_ui.input_box_load, *window);
	display_analizer(*window, window->elem_visu);
}
