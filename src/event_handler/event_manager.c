/*
** EPITECH PROJECT, 2018
** event manager
** File description:
** my_world
*/

#include "my_world.h"

void analyse_event(window_t *window, map_node_t **map2d)
{
	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->m_window);
}
