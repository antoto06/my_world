/*
** EPITECH PROJECT, 2018
** generation
** File description:
** 2D
*/

#include "my_world.h"

sfVector2f **create_2d_map(int map3d[MAP_X][MAP_Y])
{
	sfVector2f **map2d;
	int i = 0;
	int j = 0;

	map2d = malloc(sizeof(sfVector2f *) * MAP_X);
	while (i < MAP_X) {
		map2d[i] = malloc(sizeof(sfVector2f) * MAP_Y);
		while (j < MAP_Y) {
			map2d[i][j] = project_iso_point(j * SCALING_X, i * SCALING_Y,
						map3d[i][j] * SCALING_Z);
			map2d[i][j].x += 700;
			map2d[i][j].y += 250;
			j++;
		}
		j = 0;
		i++;
	}
	return map2d;
}
