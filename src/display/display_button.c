/*
** EPITECH PROJECT, 2018
** display button
** File description:
** my_world
*/

#include "my_world.h"

void display_button_translate(window_t window, button_t *buttons)
{
	int i = 0;

	while (i < 4) {
		sfRenderWindow_drawRectangleShape(window.m_window, buttons[i].shape, NULL);
		sfRenderWindow_drawText(window.m_window, buttons[i].message, NULL);
		i++;
	}
}
