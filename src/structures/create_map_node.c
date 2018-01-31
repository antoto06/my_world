/*
** EPITECH PROJECT, 2018
** create map noe
** File description:
** world
*/

#include "my_world.h"

sfVector2f *get_convex_points(sfVector2f position)
{
	sfVector2f *vector_array = malloc(sizeof(sfVector2f) * 4);

	vector_array[0] = position;
	vector_array[1].x = position.x + SCALING_X;
	vector_array[1].y = position.y;
	vector_array[2].x = position.x + SCALING_X;
	vector_array[2].y = position.y + SCALING_Y;
	vector_array[3].x = position.x;
	vector_array[3].y = position.y + SCALING_Y;
	return vector_array;
}

map_node_t create_map_node(int x, int y, int z, window_t window)
{
	map_node_t node;

	node.iso_point = project_iso_point(y * SCALING_X, x * SCALING_Y,
					z * SCALING_Z);
	node.iso_point.x += window.size.x;
	node.iso_point.y += window.size.y - 2 * SCALING_Y;
	node.hover_shape = sfCircleShape_create();
	node.hover_shape_txtr = sfTexture_createFromFile(HOVER_SHAPE, NULL);
	node.node_shape = sfConvexShape_create();
	node.node_txtr = sfTexture_createFromFile(CONVEX_SHAPE, NULL);
	node.convex_points = get_convex_points(node.iso_point);
	sfConvexShape_setTexture(node.node_shape, node.node_txtr, sfFalse);
	sfCircleShape_setTexture(node.hover_shape, node.hover_shape_txtr, sfFalse);
	sfCircleShape_setRadius(node.hover_shape, 5.0);
	sfCircleShape_setPosition(node.hover_shape, node.iso_point);
	return node;
}
