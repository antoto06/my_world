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

void add_button_manager(button_t button_tmp, window_t *window,
	map_node_t **map2d, sfMouseButtonEvent mouse_event)
{
	sfVector2u tmp;

	if (is_hovered(map2d) == sfTrue
	&& window->window_ui.tools_state.element == sfFalse) {
		tmp = get_hovered_point(map2d);
		map2d[tmp.x][tmp.y].element.active = sfTrue;
	}
	if (button_is_clicked(button_tmp, mouse_event) == sfTrue
	&& window->window_ui.tools_state.element == sfTrue) {
		change_button_texture(button_tmp, BUTTON_GREEN_BURN);
		window->window_ui.tools_state.element = sfFalse;
	} else if (button_is_clicked(button_tmp, mouse_event) == sfTrue
	&& window->window_ui.tools_state.element == sfFalse) {
		change_button_texture(button_tmp, BUTTON_GREEN);
		window->window_ui.tools_state.element = sfTrue;
	}
}

void tools_button_manager(sfMouseButtonEvent mouse_event, window_t *window,
		map_node_t **map2d)
{
	button_t *buttons_tmp = window->window_ui.button_tools;
	button_t add_button = window->window_ui.button_tools[2];
	button_t next_button = window->window_ui.button_tools[3];

	elevate_button_manager(buttons_tmp, window, map2d, mouse_event);
	dig_button_manager(buttons_tmp, window, map2d, mouse_event);
	add_button_manager(add_button, window, map2d, mouse_event);
	manage_elem(window, map2d, next_button, mouse_event);
}
