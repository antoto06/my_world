/*
** EPITECH PROJECT, 2018
** generation
** File description:
** 2D
*/

#include "my_world.h"

map_node_t **create_2d_map(int map3d[MAP_X][MAP_Y])
{
	map_node_t **map2d;
	int i = 0;
	int j = 0;

	map2d = malloc(sizeof(map_node_t *) * MAP_X);
	while (i < MAP_X) {
		map2d[i] = malloc(sizeof(map_node_t) * MAP_Y);
		while (j < MAP_Y) {
			map2d[i][j] = create_map_node(i, j, map3d[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return map2d;
}
