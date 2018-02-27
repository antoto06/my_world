/*
** EPITECH PROJECT, 2018
** key manager
** File description:
** world
*/

#include "my_world.h"

void key_translate(map_node_t **map2d, sfKeyEvent key)
{
	if (key.code == sfKeyUp)
		button_translate(map2d, 0, -1);
	if (key.code == sfKeyDown)
		button_translate(map2d, 0, 1);
	if (key.code == sfKeyLeft)
		button_translate(map2d, -1, 0);
	if (key.code == sfKeyRight)
		button_translate(map2d, 1, 0);
}

void shortcut_tools(sfKeyEvent key, window_t *window)
{
	if (window->window_ui.ui.tools_state.elevate == sfFalse
	&& key.code == sfKeyE) {
		/* change_button_texture(buttons_tmp[0], BUTTON_GREEN_BURN); */
		/* window->window_ui.tools_state.elevate = sfTrue; */
	} else if (window->window_ui.ui.tools_state.elevate == sfTrue
	&& key.code == sfKeyD) {
		/* change_button_texture(buttons_tmp[0], BUTTON_GREEN_BURN); */
		/* window->window_ui.tools_state.elevate = sfTrue; */
	}
}

void key_manager(window_t *window, sfKeyEvent key ,map_node_t **map2d)
{
	key_translate(map2d, key);
	(void)window;
}
