/*
** EPITECH PROJECT, 2018
** button_click
** File description:
** world
*/

#include "my_world.h"

sfBool button_is_clicked(button_t button, sfMouseButtonEvent click_pos)
{
	sfVector2f mouse_click = {(float)click_pos.x, (float)click_pos.y};

	if (mouse_click.x > (button.pos.x)
	&& mouse_click.x < (button.pos.x + button.size.x)) {
		if (mouse_click.y > (button.pos.y)
		&& mouse_click.y < (button.pos.y + button.size.y)) {
			return sfTrue;
		}
	}
	return sfFalse;
}

sfBool button_is_hovered(button_t button, sfMouseMoveEvent mouse_evt)
{
	sfVector2f mouse_pos = {(float)mouse_evt.x, (float)mouse_evt.y};

	if (mouse_pos.x > (button.pos.x)
	&& mouse_pos.x < (button.pos.x + button.size.x)) {
		if (mouse_pos.y > (button.pos.y)
		&& mouse_pos.y < (button.pos.y + button.size.y)) {
			return sfTrue;
		}
	}
	return sfFalse;
}
