/*
** EPITECH PROJECT, 2018
** create
** File description:
** window
*/

#include "my_world.h"

window_t create_window(int x, int y)
{
	window_t window;
	sfVideoMode mode_tmp = {x, y, 32};

	window.m_window = sfRenderWindow_create(mode_tmp,
			"My_World", sfClose | sfResize, NULL);
	sfRenderWindow_setFramerateLimit(window.m_window, 60);
	return window;
}
