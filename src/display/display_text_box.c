/*
** EPITECH PROJECT, 2018
** text_box
** File description:
** world
*/

#include "my_world.h"

void display_text_box(text_box_t box, window_t window)
{
	sfRenderWindow_drawSprite(window.m_window, box.panel_sprt, NULL);
	sfRenderWindow_drawText(window.m_window, box.dynamic_txt, NULL);
	sfRenderWindow_drawText(window.m_window, box.panel_txt, NULL);
	display_simple_button(window, box.buttons[0]);
	display_simple_button(window, box.buttons[1]);
}
