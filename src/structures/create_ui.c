/*
** EPITECH PROJECT, 2018
** create ui
** File description:
** world
*/

#include "my_world.h"

sfVector2f get_position_by_percent(window_t window,
		int perc_x, int perc_y)
{
	sfVector2f position;

	position.x = (perc_x * window.size.x) / 100;
	position.y = (perc_y * window.size.y) / 100;
	return position;
}

button_t *create_translate_buttons(window_t window)
{
	sfVector2f button_left = get_position_by_percent(window, 0, 25);
	sfVector2f button_right = get_position_by_percent(window, 6, 25);
	sfVector2f button_down = get_position_by_percent(window, 3, 30);
	sfVector2f button_top = get_position_by_percent(window, 3, 20);
	sfVector2f button_zoomi = get_position_by_percent(window, 3, 40);
	sfVector2f button_zoomo = get_position_by_percent(window, 3, 45);
	button_t *translate = malloc(sizeof(button_t) * 6);

	translate[0] = create_button(button_left, "left", "move left");
	translate[1] = create_button(button_right, "right", "move right");
	translate[2] = create_button(button_down, "down", "move up");
	translate[3] = create_button(button_top, "up", "move down");
	translate[4] = create_button(button_zoomi, "in", "zoom in");
	translate[5] = create_button(button_zoomo, "out", "zoom out");
	return translate;
}

button_t *create_application_buttons(window_t window)
{
	sfVector2f button_load = get_position_by_percent(window, 87, 1);
	sfVector2f button_save = get_position_by_percent(window, 87, 7);
	sfVector2f button_quit = get_position_by_percent(window, 94, 1);
	sfVector2f button_selection = get_position_by_percent(window, 80, 1);
	button_t *application = malloc(sizeof(button_t) * 4);

	application[0] = create_button(button_load, "load", "load a new map");
	application[1] = create_button(button_quit, "quit", "quit application");
	application[2] = create_button(button_selection, "corner",
			"select system");
	application[3] = create_button(button_save, "save", "save your work");
	return application;
}

button_t *create_tools_button(window_t window)
{
	sfVector2f button_elevate = get_position_by_percent(window, 1, 1);
	sfVector2f button_dig = get_position_by_percent(window, 7, 1);
	sfVector2f button_elem = get_position_by_percent(window, 14, 1);
	button_t *tools = malloc(sizeof(button_t) * 3);

	tools[0] = create_button(button_elevate, "elevate", "create mountains");
	tools[1] = create_button(button_dig, "dig", "create holes");
	tools[2] = create_button(button_elem, "add", "add elements");
	return tools;
}

ui_size_t get_ui_size(void)
{
	ui_size_t ui_size;

	ui_size.tr_size = 6;
	ui_size.app_size = 4;
	ui_size.tools_size = 3;
	return ui_size;
}

ui_t create_ui(window_t window)
{
	ui_t ui;

	ui.ui_size = get_ui_size();
	ui.button_translate = create_translate_buttons(window);
	ui.button_application = create_application_buttons(window);
	ui.button_tools = create_tools_button(window);
	ui.input_box = create_text_box(window, "Save your map!", "Save");
	ui.input_box_load = create_text_box(window, "Load a new map", "Load");
	ui.tools_state.elevate = sfFalse;
	ui.tools_state.dig = sfFalse;
	ui.tools_state.corner = sfTrue;
	ui.tools_state.save = sfFalse;
	ui.tools_state.load = sfFalse;
	ui.tools_state.element = sfTrue;
	return ui;
}
