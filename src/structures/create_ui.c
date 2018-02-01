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
	sfVector2f button1_pos = {500, 500};

	ui.button_translate = create_button(button1_pos, "button");
	return ui;
}
