/*
** EPITECH PROJECT, 2018
** text_box
** File description:
** world
*/

#include "my_world.h"

void button_text_box(window_t *window, sfMouseButtonEvent mouse_evt)
{
	button_t *buttons_save = window->window_ui.input_box.buttons;
	button_t *buttons_load = window->window_ui.input_box_load.buttons;
	char *stock_tmp_save = window->window_ui.input_box.stock_str;
	char *stock_tmp_load = window->window_ui.input_box_load.stock_str;

	if (button_is_clicked(buttons_save[0], mouse_evt) == sfTrue
	|| button_is_clicked(buttons_load[0], mouse_evt) == sfTrue)
		handle_textbox_action(window, stock_tmp_save, stock_tmp_load);
	if (button_is_clicked(buttons_save[1], mouse_evt) == sfTrue
	|| button_is_clicked(buttons_load[1], mouse_evt) == sfTrue) {
		handle_exit_click(window, mouse_evt);
	}
}

void handle_del_input(window_t *window)
{
	char *tmp;
	int pos_del = 0;

	if (window->window_ui.tools_state.save == sfTrue) {
		tmp = window->window_ui.input_box.stock_str;
		pos_del = my_strlen(tmp) - 1;
		window->window_ui.input_box.stock_str[pos_del] = '\0';
		sfText_setString(window->window_ui.input_box.dynamic_txt,
			window->window_ui.input_box.stock_str);
	} else if (window->window_ui.tools_state.load == sfTrue) {
		tmp = window->window_ui.input_box_load.stock_str;
		pos_del = my_strlen(tmp) - 1;
		window->window_ui.input_box_load.stock_str[pos_del] = '\0';
		sfText_setString(window->window_ui.input_box_load.dynamic_txt,
			window->window_ui.input_box_load.stock_str);
	}
}

void handle_input(window_t *window, char *input_str)
{
	if (window->window_ui.tools_state.save == sfTrue) {
		window->window_ui.input_box.stock_str =
			my_strcat_malloc(window->window_ui.input_box.stock_str,
			input_str);
		sfText_setString(window->window_ui.input_box.dynamic_txt,
			window->window_ui.input_box.stock_str);
	} else if (window->window_ui.tools_state.load == sfTrue) {
		window->window_ui.input_box_load.stock_str =
			my_strcat_malloc(
			window->window_ui.input_box_load.stock_str, input_str);
		sfText_setString(window->window_ui.input_box_load.dynamic_txt,
			window->window_ui.input_box_load.stock_str);
	}
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
	handle_input(window, input_str);
	free(input_str);
	return 0;
}
