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

	       button.pos.x, button.pos.y);
	if (mouse_click.x > (button.pos.x - button.size.x)
	&& mouse_click.x < (button.pos.x + button.size.x)) {
		if (mouse_click.y > (button.pos.y - button.size.y)
		&& mouse_click.y < (button.pos.y + button.size.y)) {
			return sfTrue;
		}
	}
	return sfFalse;
}
