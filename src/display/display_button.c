/*
** EPITECH PROJECT, 2018
** display button
** File description:
** my_world
*/

#include "my_world.h"

void display_simple_button(window_t window, button_t button)
{
	sfRenderWindow_drawRectangleShape(window.m_window,
				button.shape, NULL);
	sfRenderWindow_drawText(window.m_window,
				button.message, NULL);
}

void display_button_application(window_t window, button_t *buttons)
{
	int i = 0;

	while (i < 4) {
		if (buttons[i].hovered == sfFalse) {
			sfRenderWindow_drawRectangleShape(window.m_window,
				buttons[i].shape, NULL);
		} else {
			sfRenderWindow_drawRectangleShape(window.m_window,
				buttons[i].shape_hover, NULL);
		}
		sfRenderWindow_drawText(window.m_window,
				buttons[i].message, NULL);
		i++;
	}
}

void display_button_translate(window_t window, button_t *buttons)
{
	int i = 0;

	while (i < 4) {
		if (buttons[i].hovered == sfFalse) {
			sfRenderWindow_drawRectangleShape(window.m_window,
				buttons[i].shape, NULL);
		} else {
			sfRenderWindow_drawRectangleShape(window.m_window,
				buttons[i].shape_hover, NULL);
		}
		sfRenderWindow_drawText(window.m_window,
				buttons[i].message, NULL);
		i++;
	}
}

void display_button_tools(window_t window, button_t *buttons)
{
	int i = 0;

	while (i < 2) {
		if (buttons[i].hovered == sfFalse) {
			sfRenderWindow_drawRectangleShape(window.m_window,
				buttons[i].shape, NULL);
		} else {
			sfRenderWindow_drawRectangleShape(window.m_window,
				buttons[i].shape_hover, NULL);
		}
		sfRenderWindow_drawText(window.m_window,
				buttons[i].message, NULL);
		i++;
	}
}
