/*
** EPITECH PROJECT, 2018
** translate button
** File description:
** world
*/

#include "my_world.h"

void button_translate_left(map_node_t **map2d)
{
	int i = 0;
	int j = 0;

	while (i < MAP_X) {
		while (j < MAP_Y) {
			map2d[i][j].iso_point.x += 1;
			map2d[i][j].iso_point.y += 1;
			sfCircleShape_setPosition(map2d[i][j].hover_shape,
					map2d[i][j].iso_point);
			j++;
		}
		i++;
		j = 0;
	}
}
