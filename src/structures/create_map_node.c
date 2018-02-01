/*
** EPITECH PROJECT, 2018
** create map node
** File description:
** world
*/

#include "my_world.h"

map_node_t create_map_node(int x, int y, int z, window_t window)
{
	map_node_t node;
	sfVector2f hover_pos;

	node.iso_point = project_iso_point(y * SCALING_X, x * SCALING_Y,
					z * SCALING_Z);
	node.iso_point.x += window.size.x;
	node.iso_point.y += window.size.y - 2 * SCALING_Y;
	hover_pos.x = node.iso_point.x - 10;
	hover_pos.y = node.iso_point.y - 10;
	node.hover_shape = sfCircleShape_create();
	node.hover_shape_txtr = sfTexture_createFromFile(HOVER_SHAPE, NULL);
	sfCircleShape_setTexture(node.hover_shape, node.hover_shape_txtr, sfFalse);
	sfCircleShape_setRadius(node.hover_shape, 10.0);
	sfCircleShape_setPosition(node.hover_shape, hover_pos);
	node.hover_visible = sfFalse;
	return node;
}
