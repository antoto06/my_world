/*
** EPITECH PROJECT, 2018
** free
** File description:
** ui
*/

#include "my_world.h"

void free_ui(ui_t ui)
{
	free_button_array(ui.button_translate, ui.ui_size.tr_size);
	free_button_array(ui.button_application, ui.ui_size.app_size);
	free_button_array(ui.button_tools, ui.ui_size.tools_size);
}
