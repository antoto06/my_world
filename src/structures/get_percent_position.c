/*
** EPITECH PROJECT, 2018
** percent
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

