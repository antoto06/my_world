/*
** EPITECH PROJECT, 2018
** text_box
** File description:
** world
*/

#include "my_world.h"

void manage_save_system(window_t *window)
{
	if (window->window_ui.tools_state.save == sfFalse)
		window->window_ui.tools_state.save = sfTrue;
}

void button_text_box(window_t *window, sfMouseButtonEvent mouse_evt)
{
	button_t *buttons_tmp = window->window_ui.input_box.buttons;
	char *stock_tmp = window->window_ui.input_box.stock_str;

	if (button_is_clicked(buttons_tmp[0], mouse_evt) == sfTrue) {
		if (stock_tmp) {
			save_map(stock_tmp, *window);
			free(window->window_ui.input_box.stock_str);
			window->window_ui.input_box.stock_str = NULL;
			window->window_ui.tools_state.save = sfFalse;
		}
	}
	if (button_is_clicked(buttons_tmp[1], mouse_evt) == sfTrue) {
		window->window_ui.tools_state.save = sfFalse;
		free(window->window_ui.input_box.stock_str);
		window->window_ui.input_box.stock_str = NULL;
	}
}

void handle_del_input(window_t *window)
{
	char *tmp;
	int pos_del = 0;

	tmp = window->window_ui.input_box.stock_str;
	pos_del = my_strlen(tmp) - 1;
	window->window_ui.input_box.stock_str[pos_del] = '\0';
	sfText_setString(window->window_ui.input_box.dynamic_txt,
		window->window_ui.input_box.stock_str);
}

int manage_text_box(window_t *window, sfTextEvent input_txt)
{
	char *input_str = NULL;

	if (input_txt.unicode == 13)
		return 1;
	if (input_txt.unicode == 8) {
		handle_del_input(window);
		return 0;
	}
	input_str = malloc(sizeof(char) * 2);
	input_str[0] = input_txt.unicode;
	input_str[1] = '\0';
	window->window_ui.input_box.stock_str = \
	my_strcat_malloc(window->window_ui.input_box.stock_str,
				input_str);
	sfText_setString(window->window_ui.input_box.dynamic_txt,
		window->window_ui.input_box.stock_str);
	free(input_str);
	return 0;
}
