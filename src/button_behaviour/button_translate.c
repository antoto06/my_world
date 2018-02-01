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
			map2d[i][j].iso_point.x += 0.01;
			map2d[i][j].iso_point.y += 0.01;
			j++;
		}
		i++;
		j = 0;
	}
}
