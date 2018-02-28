/*
** EPITECH PROJECT, 2018
** shortcut_tools
** File description:
** world
*/

#include "my_world.h"

void shortcut_tools_dig(sfKeyEvent key, window_t *window,
	button_t button_down)
{
	if (window->window_ui.tools_state.dig == sfFalse
	&& key.code == sfKeyD) {
		change_button_texture(button_down, BUTTON_GREEN_BURN);
		window->window_ui.tools_state.dig = sfTrue;
	} else if (window->window_ui.tools_state.dig == sfTrue
	&& key.code == sfKeyD) {
		change_button_texture(button_down, BUTTON_GREEN);
		window->window_ui.tools_state.dig = sfFalse;
	}
}

void shortcut_tools_elevate(sfKeyEvent key, window_t *window,
	button_t button_up)
{
	if (window->window_ui.tools_state.elevate == sfFalse
	&& key.code == sfKeyE) {
		change_button_texture(button_up, BUTTON_GREEN_BURN);
		window->window_ui.tools_state.elevate = sfTrue;
	} else if (window->window_ui.tools_state.elevate == sfTrue
	&& key.code == sfKeyE) {
		change_button_texture(button_up, BUTTON_GREEN);
		window->window_ui.tools_state.elevate = sfFalse;
	}
}

void shortcut_tools(sfKeyEvent key, window_t *window)
{
	button_t button_up = window->window_ui.button_tools[0];
	button_t button_down = window->window_ui.button_tools[1];

	shortcut_tools_dig(key, window, button_down);
	shortcut_tools_elevate(key, window, button_up);
}

