/*
** EPITECH PROJECT, 2018
** button
** File description:
** world
*/

#include "my_world.h"

void free_button(button_t button)
{
	sfRectangleShape_destroy(button.shape);
	sfRectangleShape_destroy(button.shape_hover);
	sfTexture_destroy(button.txtr);
	sfText_destroy(button.message);
	sfFont_destroy(button.font);
	if (button.buble_str)
		free(button.buble_str);
}

void free_button_array(button_t *button, int size)
{
	int i = 0;

	while (i < size) {
		free_button(button[i]);
		i++;
	}
}
