/*
** EPITECH PROJECT, 2018
** display
** File description:
** vertex
*/

#include "my_world.h"

int display_vertex(sfRenderWindow *window, map_node_t **map2d)
{
	int i = 0;
	int j = 0;
	sfVertexArray *tmp;
	sfVertexArray *tmp_inv;

	while (i < MAP_X) {
		while (j < MAP_Y) {
			if (j != 0) {
				tmp = create_line(&map2d[i][j].iso_point,
						&map2d[i][j - 1].iso_point);
				sfRenderWindow_drawVertexArray(window, tmp, sfFalse);
				sfRenderWindow_drawCircleShape(window, map2d[i][j].hover_shape,
					NULL);
			}
			if (i != 0) {
				tmp_inv = create_line(&map2d[i][j].iso_point,
						&map2d[i - 1][j].iso_point);
				sfRenderWindow_drawVertexArray(window, tmp_inv, sfFalse);
				sfRenderWindow_drawCircleShape(window, map2d[i][j].hover_shape,
					NULL);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return 0;
}
