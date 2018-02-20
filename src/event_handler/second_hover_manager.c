/*
** EPITECH PROJECT, 2018
** hover
** File description:
** my_world
*/

#include "my_world.h"

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

void buble_hover_manager(sfMouseMoveEvent mouse_evt, window_t window)
{
	int hovered = 0;
	button_t *button_array[] = {window.window_ui.button_translate,
				window.window_ui.button_application,
				window.window_ui.button_tools};
	int size_array[] = {window.window_ui.ui_size.tr_size,
			window.window_ui.ui_size.app_size,
			window.window_ui.ui_size.tools_size};

	set_box_pos(mouse_evt, window.buble_box);
	for (int i = 0; i < 3; i++) {
		hovered = button_checker(button_array[i], mouse_evt, size_array[i]);
		if (hovered >= 0)
			printf("hit %d\n", hovered);
		hovered = -1;
	}
}
