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

ui_t create_ui(window_t window)
{
	ui_t ui;
	sfVector2f button_left = get_position_by_percent(window, 0, 25);
	sfVector2f button_right = get_position_by_percent(window, 6, 25);
	sfVector2f button_down = get_position_by_percent(window, 3, 20);
	sfVector2f button_top = get_position_by_percent(window, 3, 30);
	button_t *translate = malloc(sizeof(button_t) * 4);

	translate[0] = create_button(button_left, "left");
	translate[1] = create_button(button_right, "right");
	translate[2] = create_button(button_down, "down");
	translate[3] = create_button(button_top, "up");
	ui.button_translate = translate;
	return ui;
}
