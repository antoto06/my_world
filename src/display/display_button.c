/*
** EPITECH PROJECT, 2018
** display button
** File description:
** my_world
*/

#include "my_world.h"

void display_button(window_t window, button_t button)
{
	sfRenderWindow_drawRectangleShape(window.m_window, button.shape, NULL);
	sfRenderWindow_drawText(window.m_window, button.message, NULL);
}
