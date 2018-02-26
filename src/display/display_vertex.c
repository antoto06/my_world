/*
** EPITECH PROJECT, 2018
** display
** File description:
** vertex
*/

#include "my_world.h"

void display_point_two(int i, int j, sfRenderWindow *window,
	map_node_t **map2d)
{
	sfVertexArray *tmp;

	if (j != 0) {
		tmp = create_line(&map2d[i][j].iso_point,
				  &map2d[i][j - 1].iso_point);
		sfRenderWindow_drawVertexArray(window, tmp, sfFalse);
		if (map2d[i][j].hover_visible == sfTrue)
			sfRenderWindow_drawCircleShape(window,
					map2d[i][j].hover_shape, NULL);
	}

}

sfTexture *get_convex_txtr(map_node_t node, window_t *window)
{
	if (window->window_ui.tools_state.corner == sfTrue)
		return node.node_txtr;
	return (node.hover_visible == sfTrue) ?
		node.hover_txtr : node.node_txtr;
}

void display_point(int j, int i, window_t *window, map_node_t **map2d)
{
	sfVertexArray *tmp_inv;
	input_map_t tmp2 = map2d[0][0].input_map;

	handle_special_case(window, map2d);
	display_point_two(i, j, window->m_window, map2d);
	if (i != 0) {
		tmp_inv = create_line(&map2d[i][j].iso_point,
			&map2d[i - 1][j].iso_point);
		sfRenderWindow_drawVertexArray(window->m_window,
				tmp_inv, sfFalse);
		handle_convex_texture(map2d[i][j], window);
	}
	if (i != tmp2.len_x - 1 && j != tmp2.len_y - 1) {
		sfConvexShape_setTexture(map2d[i][j].node_shape,
			get_convex_txtr(map2d[i][j], window), sfFalse);
		sfRenderWindow_drawConvexShape(window->m_window,
					map2d[i][j].node_shape, NULL);
	}
}

int display_vertex(window_t *window, map_node_t **map2d)
{
	int i = 0;
	int j = 0;
	input_map_t tmp = window->stock_map2d[0][0].input_map;

	if (window->map_visible == sfFalse)
		return 0;
	while (i < tmp.len_x) {
		while (j < tmp.len_y) {
			display_point(j, i, window,
				window->stock_map2d);
			j++;
		}
		j = 0;
		i++;
	}
	return 0;
}
