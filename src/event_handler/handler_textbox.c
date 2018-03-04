/*
** EPITECH PROJECT, 2018
** handler
** File description:
** textbox
*/

#include "my_world.h"

void handle_textbox_action(window_t *window,
		char *stock_tmp_save, char *stock_tmp_load)
{
	if (window->window_ui.tools_state.save == sfTrue) {
		save_map(stock_tmp_save, *window);
		free(window->window_ui.input_box.stock_str);
		window->window_ui.input_box.stock_str = NULL;
		window->window_ui.tools_state.save = sfFalse;
		sfText_setString(window->window_ui.input_box.dynamic_txt, "");
		return;
	} else if (window->window_ui.tools_state.load == sfTrue) {
		load_new_map(stock_tmp_load, window);
		free(window->window_ui.input_box_load.stock_str);
		window->window_ui.input_box_load.stock_str = NULL;
		window->window_ui.tools_state.load = sfFalse;
		sfText_setString(window->window_ui.input_box_load.dynamic_txt,
				"");
		return;
	}
}

void handle_exit_click(window_t *window, sfMouseButtonEvent mouse_evt)
{
	if (window->window_ui.tools_state.save == sfTrue) {
		window->window_ui.tools_state.save = sfFalse;
		free(window->window_ui.input_box.stock_str);
		window->window_ui.input_box.stock_str = NULL;
		sfText_setString(\
		window->window_ui.input_box.dynamic_txt, "");
	} else if (window->window_ui.tools_state.load == sfTrue) {
		window->window_ui.tools_state.load = sfFalse;
		free(window->window_ui.input_box_load.stock_str);
		window->window_ui.input_box_load.stock_str = NULL;
		sfText_setString(
		window->window_ui.input_box_load.dynamic_txt, "");
	}
	(void)mouse_evt;
}

