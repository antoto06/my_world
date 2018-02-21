/*
** EPITECH PROJECT, 2018
** generation
** File description:
** 2D
*/

#include "my_world.h"

map_node_t **create_2d_map(input_map_t map3d, window_t window)
{
	map_node_t **map2d;
	int i = 0;
	int j = 0;

	map2d = malloc(sizeof(map_node_t *) * map3d.len_x);
	while (i < map3d.len_x) {
		map2d[i] = malloc(sizeof(map_node_t) * map3d.len_y);
		while (j < map3d.len_y) {
			map2d[i][j] = create_map_node(i, j,
				map3d.map[i][j], window);
			map2d[i][j].input_map = map3d;
			j++;
		}
		j = 0;
		i++;
	}
	return map2d;
}
