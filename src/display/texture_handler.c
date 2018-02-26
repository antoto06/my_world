/*
** EPITECH PROJECT, 2018
** texture handler
** File description:
** world
*/

#include "my_world.h"

void handle_special_case(window_t *window, map_node_t **map2d)
{
	if (map2d[0][0].hover_visible == sfTrue
	&& window->window_ui.tools_state.corner == sfTrue) {
		sfRenderWindow_drawCircleShape(window->m_window,
			map2d[0][0].hover_shape, NULL);
	} else if (map2d[0][0].hover_visible == sfTrue
	&& window->window_ui.tools_state.corner == sfFalse) {
		sfConvexShape_setTexture(map2d[0][0].node_shape,
			map2d[0][0].hover_txtr, sfFalse);
	} else
		sfConvexShape_setTexture(map2d[0][0].node_shape,
			map2d[0][0].node_txtr, sfFalse);
}

void handle_convex_texture(map_node_t node, window_t *window)
{
	if (node.hover_visible == sfTrue
	&& window->window_ui.tools_state.corner == sfTrue) {
		sfRenderWindow_drawCircleShape(window->m_window,
				node.hover_shape, NULL);
	}
}
