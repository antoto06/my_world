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

	while (i < MAP_X) {
		while (j < MAP_Y) {
			if (j != 0) {
				tmp = create_line(&map2d[i][j], &map2d[i][j - 1]);
				sfRenderWindow_drawVertexArray(window, tmp, sfFalse);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return 0;
}
