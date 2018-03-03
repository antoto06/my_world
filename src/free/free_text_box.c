/*
** EPITECH PROJECT, 2018
** text
** File description:
** world
*/

#include "my_world.h"

void free_text_box(text_box_t item)
{
	sfTexture_destroy(item.panel_txtr);
	sfSprite_destroy(item.panel_sprt);
	if (item.stock_str)
		free(item.stock_str);
	sfText_destroy(item.panel_txt);
	sfText_destroy(item.dynamic_txt);
	sfFont_destroy(item.font);
	if (item.buttons) {
		free_button(item.buttons[0]);
		free_button(item.buttons[1]);
	}
}
