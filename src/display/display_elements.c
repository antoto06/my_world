/*
** EPITECH PROJECT, 2018
** element
** File description:
** world
*/

#include "my_world.h"

void display_elements(window_t *window, map_node_t node)
{
	if (node.element.rendered == sfTrue) {
		sfRenderWindow_drawSprite(window->m_window,
			node.element.sprt, NULL);
	}
}

void display_analizer(window_t window, visualizer_t visu)
{
	sfRenderWindow_drawSprite(window.m_window, visu.sprt, NULL);
}
