/*
** EPITECH PROJECT, 2018
** create ui
** File description:
** world
*/

#include "my_world.h"

ui_t create_ui()
{
	ui_t ui;
	sfVector2f button_left = {500, 500};
	sfVector2f button_right = {600, 500};
	sfVector2f button_down = {700, 500};
	sfVector2f button_top = {800, 500};
	button_t *translate = malloc(sizeof(button_t) * 4);

	translate[0] = create_button(button_left, "left");
	translate[1] = create_button(button_right, "right");
	translate[2] = create_button(button_down, "down");
	translate[3] = create_button(button_top, "up");
	ui.button_translate = translate;
	return ui;
}
