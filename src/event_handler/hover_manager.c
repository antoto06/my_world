/*
** EPITECH PROJECT, 2018
** hover
** File description:
** my_world
*/

#include "my_world.h"

sfVector2u get_hovered_point(map_node_t **map2d)
{
	input_map_t tmp = map2d[0][0].input_map;
	int i = 0;
	int j = 0;
	sfVector2u hovered;

	while (i < tmp.len_x) {
		while (j < tmp.len_y) {
			if (map2d[i][j].hover_visible == sfTrue) {
				hovered.x = i;
				hovered.y = j;
				return hovered;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

sfBool is_hovered(map_node_t **map2d)
{
	input_map_t tmp = map2d[0][0].input_map;
	int i = 0;
	int j = 0;
	sfVector2f hovered;

	while (i < tmp.len_x) {
		while (j < tmp.len_y) {
			if (map2d[i][j].hover_visible == sfTrue) {
				return sfTrue;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return sfFalse;
}

void hover_manager(sfMouseMoveEvent mouse_evt, map_node_t **map2d)
{
	sfVector2f mouse_pos = {(float)mouse_evt.x, (float)mouse_evt.y};
	int i = 0;
	int j = 0;
	input_map_t tmp = map2d[0][0].input_map;

	while (i < tmp.len_x) {
		while (j < tmp.len_y) {
			map2d[i][j].hover_visible = sfFalse; 
			if (mouse_pos.x > (map2d[i][j].iso_point.x - 10)
			    && mouse_pos.x < (map2d[i][j].iso_point.x + 10)
			    && mouse_pos.y > (map2d[i][j].iso_point.y - 10)
			    && mouse_pos.y < (map2d[i][j].iso_point.y + 10)) {
				map2d[i][j].hover_visible = sfTrue;
				printf("Hover: %d %d: true\n", i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
