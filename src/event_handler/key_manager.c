/*
** EPITECH PROJECT, 2018
** key manager
** File description:
** world
*/

#include "my_world.h"

void key_translate(map_node_t **map2d, sfKeyEvent key)
{
	if (key.code == sfKeyUp)
		button_translate(map2d, 0, -1);
	if (key.code == sfKeyDown)
		button_translate(map2d, 0, 1);
	if (key.code == sfKeyLeft)
		button_translate(map2d, -1, 0);
	if (key.code == sfKeyRight)
		button_translate(map2d, 1, 0);
}

void key_manager(window_t *window, sfKeyEvent key ,map_node_t **map2d)
{
	key_translate(map2d, key);
}
