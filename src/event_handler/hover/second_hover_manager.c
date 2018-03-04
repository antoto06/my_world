/*
** EPITECH PROJECT, 2018
** hover
** File description:
** my_world
*/

#include "my_world.h"

int one_is_hovered(button_t **button_array, window_t *window,
		   sfMouseMoveEvent mouse_pos, int *size_array)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < size_array[i]; j++) {
			if (button_is_hovered(button_array[i][j],
					mouse_pos) == sfTrue) {
				window->buble_box.display = sfTrue;
				return 1;
			}
		}
	}
	window->buble_box.display = sfFalse;
	return -1;
}

int button_checker(button_t *button,
	sfMouseMoveEvent mouse_pos, int nb_button)
{
	int i = 0;

	while (i < nb_button) {
		if (button_is_hovered(button[i], mouse_pos) == sfTrue)
			return i;
		i++;
	}
	return -1;
}

void set_box_value(button_t *button, window_t *window)
{
	sfText_setString(window->buble_box.message, button->buble_str);
	button->hovered = sfTrue;
}

void unset_hovered_button(button_t *button, int size)
{
	for (int i = 0; i < size; i++)
		button[i].hovered = sfFalse;
}

void buble_hover_manager(sfMouseMoveEvent mouse_evt, window_t *window)
{
	int hovered = 0;
	button_t *button_array[] = {window->window_ui.button_translate,
				window->window_ui.button_application,
				window->window_ui.button_tools};
	int size_array[] = {window->window_ui.ui_size.tr_size,
			window->window_ui.ui_size.app_size,
			window->window_ui.ui_size.tools_size};

	set_box_pos(mouse_evt, window->buble_box);
	for (int i = 0; i < 3; i++) {
		hovered = button_checker(button_array[i],
					mouse_evt, size_array[i]);
		if (hovered >= 0) {
			set_box_value(&button_array[i][hovered], window);
		}
		else
			unset_hovered_button(button_array[i], size_array[i]);
	}
}
