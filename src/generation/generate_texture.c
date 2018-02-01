/*
** EPITECH PROJECT, 2018
** generate
** File description:
** texture
*/

#include "my_world.h"

void generate_texture(map_node_t **map2d)
{
	sfVector2f *vector_array = malloc(sizeof(sfVector2f) * 4);

	map2d[0][0].node_shape = sfConvexShape_create();
	map2d[0][0].node_txtr = sfTexture_createFromFile(CONVEX_SHAPE, NULL);
	vector_array[0] = map2d[0][0].iso_point;
	vector_array[1] = map2d[0][1].iso_point;
	vector_array[2] = map2d[1][0].iso_point;
	vector_array[3] = map2d[1][1].iso_point;
	map2d[0][0].convex_points = vector_array;
	sfConvexShape_setPointCount(map2d[0][0].node_shape, 4);
	for (int i = 0; i < 4; i++) {
		sfConvexShape_setPoint(map2d[0][0].node_shape, i, vector_array[i]);
	}
	sfConvexShape_setTexture(map2d[0][0].node_shape, map2d[0][0].node_txtr, sfFalse);
}
