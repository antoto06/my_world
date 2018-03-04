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
	hovered.x = 0;
	hovered.y = 0;
	return hovered;
}

sfBool is_hovered(map_node_t **map2d)
{
	input_map_t tmp = map2d[0][0].input_map;
	int i = 0;
	int j = 0;

	while (i < tmp.len_x) {
		while (j < tmp.len_y) {
			if (map2d[i][j].hover_visible == sfTrue)
				return sfTrue;
			j++;
		}
		j = 0;
		i++;
	}
	return sfFalse;
}

sfBool get_hovered_type(sfVector2f mouse_pos, map_node_t node, window_t window)
{
	if (mouse_pos.x > (node.iso_point.x - 10)
	&& mouse_pos.x < (node.iso_point.x + 10)
	&& mouse_pos.y > (node.iso_point.y - 10)
	&& mouse_pos.y < (node.iso_point.y + 10)
	&& window.window_ui.tools_state.corner == sfTrue)
		return sfTrue;
	if (mouse_pos.x > (node.iso_point.x - 35)
	&& mouse_pos.x < (node.iso_point.x + 35)
	&& mouse_pos.y > (node.iso_point.y)
	&& mouse_pos.y < (node.iso_point.y + 45)
	&& window.window_ui.tools_state.corner == sfFalse)
		return sfTrue;
	return sfFalse;
}

void hover_manager(sfMouseMoveEvent mouse_evt,
		map_node_t **map2d, window_t *window)
{
	sfVector2f mouse_pos = {(float)mouse_evt.x, (float)mouse_evt.y};
	int i = 0;
	int j = 0;
	input_map_t tmp = map2d[0][0].input_map;

	while (i < tmp.len_x - 1) {
		while (j < tmp.len_y - 1) {
			map2d[i][j].hover_visible = \
			get_hovered_type(mouse_pos, map2d[i][j], *window);
			manage_elem_display(*window, &map2d[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
