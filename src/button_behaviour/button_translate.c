/*
** EPITECH PROJECT, 2018
** translate button
** File description:
** world
*/

#include "my_world.h"

void button_translate(map_node_t **map2d, int x_offset, int y_offset)
{
	int i = 0;
	int j = 0;

	while (i < MAP_X) {
		while (j < MAP_Y) {
			map2d[i][j].iso_point.x += x_offset;
			map2d[i][j].iso_point.y += y_offset;
			sfCircleShape_setPosition(map2d[i][j].hover_shape,
					map2d[i][j].iso_point);
			j++;
		}
		i++;
		j = 0;
	}
}
