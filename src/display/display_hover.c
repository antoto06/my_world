/*
** EPITECH PROJECT, 2018
** hover display
** File description:
** world
*/

#include "my_world.h"

void display_buble_box(buble_box_t box, window_t window)
{
	if (box.display == sfTrue) {
		sfRenderWindow_drawText(window.m_window, box.message, NULL);
	}
}
