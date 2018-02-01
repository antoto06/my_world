/*
** EPITECH PROJECT, 2018
** display button
** File description:
** my_world
*/

#include "my_world.h"

void display_button(window_t window, button_t button[4])
{
	//malloc button without fixed size
	sfRenderWindow_drawRectangleShape(window.m_window, button[0].shape, NULL);
	sfRenderWindow_drawText(window.m_window, button[0].message, NULL);
}
