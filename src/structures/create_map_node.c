/*
** EPITECH PROJECT, 2018
** create map noe
** File description:
** world
*/

#include "my_world.h"

map_node_t create_map_node(int x, int y, int z)
{
	map_node_t node;

	node.iso_point = project_iso_point(y * SCALING_X, x * SCALING_Y,
					z * SCALING_Z);
	node.iso_point.x += 680;
	node.iso_point.y += 230;
	node.hover_shape = sfCircleShape_create();
	node.hover_shape_txtr = sfTexture_createFromFile(HOVER_SHAPE, NULL);
	sfCircleShape_setTexture(node.hover_shape, node.hover_shape_txtr, sfFalse);
	sfCircleShape_setRadius(node.hover_shape, 5.0);
	sfCircleShape_setPosition(node.hover_shape, node.iso_point);
	return node;
}
