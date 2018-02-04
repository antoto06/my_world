/*
** EPITECH PROJECT, 2018
** hover
** File description:
** my_world
*/

#include "my_world.h"

void hover_manager(sfMouseMoveEvent mouse_evt, map_node_t **map2d)
{
	sfVector2f mouse_pos = {(float)mouse_evt.x, (float)mouse_evt.y};
	int i = 0;
	int j = 0;
	input_map_t tmp4 = map2d[0][0].input_map;

	while (i < tmp4.len_x) {
		while (j < tmp4.len_y) {
			if (mouse_pos.x > (map2d[i][j].iso_point.x - 10)
			    && mouse_pos.x < (map2d[i][j].iso_point.x + 10)
			    && mouse_pos.y > (map2d[i][j].iso_point.y - 10)
			    && mouse_pos.y < (map2d[i][j].iso_point.y + 10))
				map2d[i][j].hover_visible = sfTrue;
			else
				map2d[i][j].hover_visible = sfFalse;
			j++;
		}
		j = 0;
		i++;
	}
}
