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
	input_map_t tmp = map2d[0][0].input_map;

	while (i < tmp.len_x - 1) {
		while (j < tmp.len_y - 1) {
			map2d[i][j].node_shape = sfConvexShape_create();
			if (tmp.map[i][j] == 00 && tmp.map[i + 1][j + 1] < 01 && tmp.map[i][j + 1] < 01 && tmp.map[i + 1][j] < 01)
				map2d[i][j].node_txtr = sfTexture_createFromFile(TXTR_GRASS, NULL);
			else if (tmp.map[i][j] >= 01)
				map2d[i][j].node_txtr = sfTexture_createFromFile(TXTR_ROCK, NULL);
			else
				map2d[i][j].node_txtr = sfTexture_createFromFile(TXTR_ROCK, NULL);
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
