/*
** EPITECH PROJECT, 2018
** free
** File description:
** map
*/

#include "my_world.h"

void free_input_map(input_map_t map)
{
	int i = 0;
	int len = map.len_y;

	while (i < len)
		free(map.map[i]);
	free(map.map);
}

void free_map2d(map_node_t **map2d)
{
	int i = 0;
	int j = 0;
	int len = map2d[0][0].input_map.len_x;

	while (i < len - 1) {
		while (j < len - 1) {
			sfConvexShape_destroy(map2d[i][j].node_shape);
			sfTexture_destroy(map2d[i][j].node_txtr);
			sfCircleShape_destroy(map2d[i][j].hover_shape);
			sfTexture_destroy(map2d[i][j].hover_shape_txtr);
			free(map2d[i][j].convex_points);
			j++;
		}
		j = 0;
		i++;
	}
}
