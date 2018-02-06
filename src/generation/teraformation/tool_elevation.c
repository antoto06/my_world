/*
** EPITECH PROJECT, 2018
** elevation
** File description:
** tools
*/

#include "my_world.h"

void tool_elevate(window_t *window, int x, int y)
{
	input_map_t new_input = window->stock_map2d[0][0].input_map;
	map_node_t **new_map;

	printf("elevation tool used: %d %d\n", x, y);
	new_input.map[x][y] += 01;
	new_map = create_2d_map(new_input, *window);
	generate_texture(new_map);
	window->stock_map2d = NULL;
	window->stock_map2d = new_map;
}
