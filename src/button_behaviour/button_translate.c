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
	input_map_t tmp5 = map2d[0][0].input_map;

	while (i < tmp5.len_x) {
		while (j < tmp5.len_y) {
			map2d[i][j].iso_point.x += (x_offset * 10);
			map2d[i][j].iso_point.y += (y_offset * 10);
			sfCircleShape_setPosition(map2d[i][j].hover_shape,
					map2d[i][j].iso_point);
			j++;
		}
		i++;
		j = 0;
	}
	generate_texture(map2d);
}
