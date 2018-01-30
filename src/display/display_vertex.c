/*
** EPITECH PROJECT, 2018
** display
** File description:
** vertex
*/

#include "my_world.h"

int display_vertex(sfRenderWindow *window, sfVector2f **map2d)
{
	int i = 0;
	int j = 0;
	sfVertexArray *tmp;
	sfVertexArray *tmp_inv;

	while (i < MAP_X) {
		while (j < MAP_Y) {
			if (j != 0) {
				tmp = create_line(&map2d[i][j], &map2d[i][j - 1]);
				sfRenderWindow_drawVertexArray(window, tmp, sfFalse);
			}
			if (i != 0) {
				tmp_inv = create_line(&map2d[i][j], &map2d[i - 1][j]);
				sfRenderWindow_drawVertexArray(window, tmp_inv, sfFalse);

			}
			j++;
		}
		j = 0;
		i++;
	}
	return 0;
}
