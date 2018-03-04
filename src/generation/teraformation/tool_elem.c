/*
** EPITECH PROJECT, 2018
** tool
** File description:
** elem
*/

#include "my_world.h"

void manage_elem_display(window_t window, map_node_t *node, int i, int j)
{
	if (node->element.active == sfTrue)
		return;
	if (window.window_ui.tools_state.element == sfFalse) {
		node->element.rendered = \
			node->hover_visible;
	} else {
		node->element.rendered = sfFalse;
	}
}

void tool_elem(window_t *window, int x, int y, map_node_t **map2d)
{
	input_map_t tmp = map2d[0][0].input_map;

	if (x + 1 > tmp.len_x || y + 1 > tmp.len_y)
		return;
	map2d[x][y].element.active = sfTrue;
}
