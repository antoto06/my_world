/*
** EPITECH PROJECT, 2018
** free
** File description:
** window
*/

#include "my_world.h"

void free_window(window_t window, map_node_t **map2d)
{
	sfRectangleShape_destroy(window.background);
	sfTexture_destroy(window.background_txtr);
	sfRenderWindow_destroy(window.m_window);
	free_map2d(map2d);
}

void free_all(window_t window, map_node_t **map2d)
{
	free_window(window, map2d);
	free_ui(window.window_ui);
	free_text_box(window.window_ui.input_box);
	free_text_box(window.window_ui.input_box_load);
	free_buble_box(window.buble_box);
}
