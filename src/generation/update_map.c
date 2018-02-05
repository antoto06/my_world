/*
** EPITECH PROJECT, 2018
** update
** File description:
** map
*/

#include "my_world.h"

void update_map(char *new_map_path, window_t *window)
{
	input_map_t map3d = my_rd(new_map_path);
	map_node_t **new_map = create_2d_map(map3d, *window);

	generate_texture(new_map);
	window->stock_map2d = NULL;
	window->stock_map2d = new_map;
}
