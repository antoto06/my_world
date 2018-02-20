/*
** EPITECH PROJECT, 2018
** hover
** File description:
** my_world
*/

#include "my_world.h"

void second_hover_manager(sfMouseMoveEvent mouse_evt, window_t *window)
{
	sfVector2f mouse_pos = {(float)mouse_evt.x, (float)mouse_evt.y};
	button_t *button_tmp = window->window_ui.button_translate;

	while (mouse_pos.x > button_tmp->pos.x
	&& (mouse_pos.y < button_tmp->pos.y))
		sfRenderWindow_drawText(window->m_window, HOVER_MOUSE, NULL);
}
