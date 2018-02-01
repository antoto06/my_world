/*
** EPITECH PROJECT, 2018
** hover
** File description:
** my_world
*/

#include "my_world.h"

void hover_manager(sfMouseMoveEvent mouse_evt, window_t *window,
		map_node_t **map2d)
{
	sfVector2f mouse_pos = {(float)mouse_evt.x, (float)mouse_evt.y};
	int i = 0;
	int j = 0;

	while (i < MAP_X) {
		while (j < MAP_Y) {
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
