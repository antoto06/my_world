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

void set_texture_map(map_node_t **map2d, int i, int j)
{
	input_map_t tmp = map2d[0][0].input_map;

	map2d[i][j].node_shape = sfConvexShape_create();
	if (tmp.map[i][j] == 00 && tmp.map[i + 1][j + 1] < 01
	&& tmp.map[i][j + 1] < 01 && tmp.map[i + 1][j] < 01)
		map2d[i][j].node_txtr =
			sfTexture_createFromFile(TXTR_GRASS, NULL);
	else if (tmp.map[i][j] >= 01 && tmp.map[i][j] < 5)
		map2d[i][j].node_txtr =
			sfTexture_createFromFile(TXTR_ROCK, NULL);
	else if (tmp.map[i][j] >= 05)
		map2d[i][j].node_txtr =
			sfTexture_createFromFile(TXTR_GELE, NULL);
	else if (tmp.map[i][j] <= -1)
		map2d[i][j].node_txtr =
			sfTexture_createFromFile(TXTR_WATER, NULL);
	else
		map2d[i][j].node_txtr =
			sfTexture_createFromFile(TXTR_ROCK_BURN, NULL);
}

void generate_convex_shape(map_node_t node, sfVector2f *vector_array)
{
	for (int k = 0; k < 4; k++) {
		sfConvexShape_setPoint(node.node_shape,
			k, vector_array[k]);
	}
}

void generate_texture(map_node_t **map2d)
{
	sfVector2f *vector_array;
	int j = 0;
	input_map_t tmp = map2d[0][0].input_map;

	for (int i = 0; i < tmp.len_x - 1; i++) {
		while (j < tmp.len_y - 1) {
			set_texture_map(map2d, i, j);
			vector_array = get_vector_array(map2d, i, j);
			map2d[i][j].convex_points = vector_array;
			sfConvexShape_setPointCount(map2d[i][j].node_shape, 4);
			generate_convex_shape(map2d[i][j], vector_array);
			sfConvexShape_setTexture(map2d[i][j].node_shape,
					map2d[i][j].node_txtr, sfFalse);
			j++;
		}
		j = 0;
	}
}
