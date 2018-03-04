/*
** EPITECH PROJECT, 2018
** translate button
** File description:
** world
*/

#include "my_world.h"

void set_elements_position(map_node_t node)
{
	sfVector2f tmp;

	tmp.x = node.iso_point.x - 40;
	tmp.y = node.iso_point.y - 40;
	sfSprite_setPosition(node.element.sprt, tmp);
}

void button_translate(map_node_t **map2d, int x_offset, int y_offset)
{
	int i = 0;
	int j = 0;
	input_map_t tmp5 = map2d[0][0].input_map;

	map2d[0][0].stock_translation.x += (x_offset * 10) / 2;
	map2d[0][0].stock_translation.y += (y_offset * 10) / 2;
	while (i < tmp5.len_x) {
		while (j < tmp5.len_y) {
			map2d[i][j].iso_point.x += (x_offset * 10) / 2;
			map2d[i][j].iso_point.y += (y_offset * 10) / 2;
			sfCircleShape_setPosition(map2d[i][j].hover_shape,
					map2d[i][j].iso_point);
			set_elements_position(map2d[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	generate_texture(map2d);
}

sfVector2f get_iso_point(int current_zoom,
			input_map_t tmp5, int i, int j)
{
	return project_iso_point(j * (SCALING_X + current_zoom),
		i * (SCALING_Y + current_zoom),
		tmp5.map[i][j] * (SCALING_Z + current_zoom));
}

void button_zoom(map_node_t **map2d, int offset, window_t *window)
{
	int i = 0;
	int j = 0;
	input_map_t tmp5 = map2d[0][0].input_map;
	static int current_zoom = 0;

	current_zoom += offset;
	while (i < tmp5.len_x) {
		while (j < tmp5.len_y) {
			map2d[i][j].iso_point = get_iso_point(current_zoom,
						tmp5, i, j);
			map2d[i][j].iso_point.x += (window->size.x / 2);
			map2d[i][j].iso_point.y += (window->size.y / 2) - 2
				* (SCALING_Y + current_zoom);
			sfCircleShape_setPosition(map2d[i][j].hover_shape,
					map2d[i][j].iso_point);
			set_elements_position(map2d[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
}
