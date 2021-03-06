/*
** EPITECH PROJECT, 2018
** create map node
** File description:
** world
*/

#include "my_world.h"

void set_sub_node(map_node_t *node, sfVector2f hover_pos)
{
	node->hover_shape = sfCircleShape_create();
	node->hover_shape_txtr = sfTexture_createFromFile(HOVER_SHAPE, NULL);
	node->hover_txtr = sfTexture_createFromFile(TXTR_GRASS_HOVER, NULL);
	sfCircleShape_setTexture(node->hover_shape,
			node->hover_shape_txtr, sfFalse);
	sfCircleShape_setRadius(node->hover_shape, 10.0);
	sfCircleShape_setPosition(node->hover_shape, hover_pos);
}

map_node_t create_map_node(int x, int y, int z, window_t window)
{
	map_node_t node;
	sfVector2f hover_pos;

	node.iso_point = project_iso_point(y * SCALING_X, x * SCALING_Y,
					z * SCALING_Z);
	node.iso_point.x += (window.size.x / 2);
	node.iso_point.y += (window.size.y / 2) - 2 * SCALING_Y;
	node.stock_translation.x = 0;
	node.stock_translation.y = 0;
	hover_pos.x = node.iso_point.x - 10;
	hover_pos.y = node.iso_point.y - 10;
	node.hover_visible = sfFalse;
	set_sub_node(&node, hover_pos);
	node.element = create_element(hover_pos);
	return node;
}
