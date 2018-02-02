/*
** EPITECH PROJECT, 2018
** generate
** File description:
** texture
*/

#include "my_world.h"

sfVector2f *get_vector_array(map_node_t **map2d, int i, int j)
{
	sfVector2f *vector_array = malloc(sizeof(sfVector2f) * 4);

	vector_array[0] = map2d[i][j].iso_point;
	vector_array[1] = map2d[i + 1][j].iso_point;
	vector_array[2] = map2d[i + 1][j + 1].iso_point;
	vector_array[3] = map2d[i][j + 1].iso_point;
	return vector_array;
}

void generate_texture(map_node_t **map2d)
{
	sfVector2f *vector_array;
	int i = 0;
	int j = 0;

	while (i < MAP_X - 1) {
		while (j < MAP_Y - 1) {
			map2d[i][j].node_shape = sfConvexShape_create();
			map2d[i][j].node_txtr = sfTexture_createFromFile(CONVEX_SHAPE, NULL);
			vector_array = get_vector_array(map2d, i, j);
			map2d[i][j].convex_points = vector_array;
			sfConvexShape_setPointCount(map2d[i][j].node_shape, 4);
			for (int k = 0; k < 4; k++) {
				sfConvexShape_setPoint(map2d[i][j].node_shape, k, vector_array[k]);
			}
			sfConvexShape_setTexture(map2d[i][j].node_shape, map2d[i][j].node_txtr, sfFalse);
			j++;
		}
		i++;
		j = 0;
	}
}
