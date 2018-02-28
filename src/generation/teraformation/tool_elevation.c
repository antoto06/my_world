/*
** EPITECH PROJECT, 2018
** elevation
** File description:
** tools
*/

#include "my_world.h"

void tool_elevate_zone(window_t *window, int x, int y)
{
	input_map_t new_input = window->stock_map2d[0][0].input_map;
	map_node_t **new_map;

	if (x + 2 > new_input.len_x || y + 2 > new_input.len_y)
		return;
	new_input.map[x][y] += 1;
	new_input.map[x + 1][y] += 1;
	new_input.map[x][y + 1] += 1;
	new_input.map[x + 1][y + 1] += 1;
	new_map = create_2d_map(new_input, *window);
	generate_texture(new_map);
	window->stock_map2d = NULL;
	window->stock_map2d = new_map;
}

void tool_elevate(window_t *window, int x, int y, map_node_t **map2d)
{
	input_map_t new_input = window->stock_map2d[0][0].input_map;
	map_node_t **new_map;
	int new_z = 0;

	if (window->window_ui.tools_state.corner == sfFalse) {
		tool_elevate_zone(window, x, y);
	} else {
		/* new_input.map[x][y] += 01; */
		/* new_map = create_2d_map(new_input, *window); */
		/* generate_texture(new_map); */
		/* window->stock_map2d = NULL; */
		/* window->stock_map2d = new_map; */
		new_z = map2d[0][0].input_map.map[x][y] + 01;
		map2d[0][0].input_map.map[x][y] += 01;
		map2d[x][y].iso_point = project_iso_point(y * SCALING_X,
			x * SCALING_Y, new_z * SCALING_Z);
		map2d[x][y].iso_point.x += (window->size.x / 2);
		map2d[x][y].iso_point.y += (window->size.y / 2) - (2 * SCALING_Y);
		sfCircleShape_setPosition(map2d[x][y].hover_shape,
				map2d[x][y].iso_point);
		window->stock_map2d = map2d;
		generate_texture(map2d);
	}
}
