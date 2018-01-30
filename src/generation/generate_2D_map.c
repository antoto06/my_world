/*
** EPITECH PROJECT, 2018
** generation
** File description:
** 2D
*/

#include "my_world.h"

sfVector2f **create_2d_map(int **map3d)
{
	sfVector2f map2d[MAP_X][MAP_Y];
	int i = 0;
	int j = 0;

	while (i < MAP_X) {
		while (j < MAP_Y) {
			map2d[i][j] = project_iso_point(j * SCALING_X, i * SCALING_Y,
						map3d[i][j] * SCALING_Z);
			j++;
		}
		j = 0;
		i++;
	}
	return map2d;
}
