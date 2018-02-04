/*
** EPITECH PROJECT, 2018
** display
** File description:
** vertex
*/

#include "my_world.h"

void display_point(int j, int i, sfRenderWindow *window, map_node_t **map2d)
{
	sfVertexArray *tmp;
	sfVertexArray *tmp_inv;
	input_map_t tmp2 = map2d[0][0].input_map;

	if (map2d[0][0].hover_visible == sfTrue)
		sfRenderWindow_drawCircleShape(window, map2d[0][0].hover_shape,
					       NULL);
	if (j != 0) {
		tmp = create_line(&map2d[i][j].iso_point,
				  &map2d[i][j - 1].iso_point);
		sfRenderWindow_drawVertexArray(window, tmp, sfFalse);
		if (map2d[i][j].hover_visible == sfTrue)
			sfRenderWindow_drawCircleShape(window, map2d[i][j].hover_shape,
						       NULL);
	}
	if (i != 0) {
		tmp_inv = create_line(&map2d[i][j].iso_point,
				      &map2d[i - 1][j].iso_point);
		sfRenderWindow_drawVertexArray(window, tmp_inv, sfFalse);
		if (map2d[i][j].hover_visible == sfTrue)
			sfRenderWindow_drawCircleShape(window, map2d[i][j].hover_shape,
						       NULL);
	}
	if (i != tmp2.len_x - 1 && j != tmp2.len_y - 1)
		sfRenderWindow_drawConvexShape(window, map2d[i][j].node_shape, NULL);
}

int display_vertex(sfRenderWindow *window, map_node_t **map2d)
{
	int i = 0;
	int j = 0;
	input_map_t tmp = map2d[0][0].input_map;

	while (i < tmp.len_x) {
		while (j < tmp.len_y) {
			display_point(j, i, window, map2d);
			j++;
		}
		j = 0;
		i++;
	}
	return 0;
}
