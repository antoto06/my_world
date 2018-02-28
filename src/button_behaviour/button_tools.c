/*
** EPITECH PROJECT, 2018
** tools
** File description:
** buttons
*/

#include "my_world.h"

void sound_manager(void)
{
	sfMusic *music;

	music = sfMusic_createFromFile(SONG_DUG);
	sfMusic_play(music);
}

void elevate_button_manager(button_t *buttons_tmp, window_t *window,
	map_node_t **map2d, sfMouseButtonEvent mouse_event)
{
	sfVector2u tmp;

	if (is_hovered(map2d) == sfTrue
	    && window->window_ui.tools_state.elevate == sfTrue) {
		tmp = get_hovered_point(map2d);
		tool_elevate(window, tmp.x, tmp.y, map2d);
	}
	if (button_is_clicked(buttons_tmp[0], mouse_event) == sfTrue
	&& window->window_ui.tools_state.elevate == sfFalse) {
		change_button_texture(buttons_tmp[0], BUTTON_GREEN_BURN);
		window->window_ui.tools_state.elevate = sfTrue;
	} else if (button_is_clicked(buttons_tmp[0], mouse_event) == sfTrue
	&& window->window_ui.tools_state.elevate == sfTrue) {
		change_button_texture(buttons_tmp[0], BUTTON_GREEN);
		window->window_ui.tools_state.elevate = sfFalse;
	}
}

void dig_button_manager(button_t *buttons_tmp, window_t *window,
	map_node_t **map2d, sfMouseButtonEvent mouse_event)
{
	sfVector2u tmp;

	if (is_hovered(map2d) == sfTrue
	    && window->window_ui.tools_state.dig == sfTrue) {
		sound_manager();
		tmp = get_hovered_point(map2d);
		tool_dig(window, tmp.x, tmp.y, map2d);
	}
	if (button_is_clicked(buttons_tmp[1], mouse_event) == sfTrue
	&& window->window_ui.tools_state.dig == sfFalse) {
		change_button_texture(buttons_tmp[1], BUTTON_GREEN_BURN);
		window->window_ui.tools_state.dig = sfTrue;
	} else if (button_is_clicked(buttons_tmp[1], mouse_event) == sfTrue
	&& window->window_ui.tools_state.dig == sfTrue) {
		change_button_texture(buttons_tmp[1], BUTTON_GREEN);
		window->window_ui.tools_state.dig = sfFalse;
	}
}

void tools_button_manager(sfMouseButtonEvent mouse_event, window_t *window,
		map_node_t **map2d)
{
	button_t *buttons_tmp = window->window_ui.button_tools;

	elevate_button_manager(buttons_tmp, window, map2d, mouse_event);
	dig_button_manager(buttons_tmp, window, map2d, mouse_event);
}
