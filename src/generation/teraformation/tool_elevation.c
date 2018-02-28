/*
** EPITECH PROJECT, 2018
** elevation
** File description:
** tools
*/

#include "my_world.h"

void change_iso_point(window_t *window, int x, int y, map_node_t **map2d)
{
	int new_z = 0;
	float stock_x = map2d[0][0].stock_translation.x;
	float stock_y = map2d[0][0].stock_translation.y;

	new_z = map2d[0][0].input_map.map[x][y] + 01;
	map2d[0][0].input_map.map[x][y] += 01;
	map2d[x][y].iso_point = project_iso_point(y * SCALING_X,
			x * SCALING_Y, new_z * SCALING_Z);
	map2d[x][y].iso_point.x += (window->size.x / 2) + stock_x;
	map2d[x][y].iso_point.y += (window->size.y / 2) \
			- (2 * SCALING_Y) + stock_y;
	sfCircleShape_setPosition(map2d[x][y].hover_shape,
			map2d[x][y].iso_point);

}

void tool_elevate_zone(window_t *window, int x, int y, map_node_t **map2d)
{
	input_map_t new_input = map2d[0][0].input_map;

	if (x + 2 > new_input.len_x || y + 2 > new_input.len_y)
		return;
	change_iso_point(window, x, y, map2d);
	change_iso_point(window, x + 1, y, map2d);
	change_iso_point(window, x, y + 1, map2d);
	change_iso_point(window, x + 1, y + 1, map2d);
	window->stock_map2d = map2d;
	generate_texture(map2d);
}

void tool_elevate(window_t *window, int x, int y, map_node_t **map2d)
{
	if (window->window_ui.tools_state.corner == sfFalse) {
		tool_elevate_zone(window, x, y, map2d);
	} else {
		change_iso_point(window, x, y, map2d);
		window->stock_map2d = map2d;
		generate_texture(map2d);
	}
}
