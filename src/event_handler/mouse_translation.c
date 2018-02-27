/*
** EPITECH PROJECT, 2018
** mouse
** File description:
** world
*/

#include "my_world.h"

void mouse_translation(map_node_t **map2d, window_t *window,
	sfMouseMoveEvent mouse_mv)
{
	sfVector2f mouse = {(float)mouse_mv.x, (float)mouse_mv.y};
	int max_x = window->size.x;
	int max_y = window->size.y;

	if ((int)mouse.x < 50)
		button_translate(map2d, -1, 0);
	if ((int)mouse.x > max_x - 50)
		button_translate(map2d, 1, 0);
	if ((int)mouse.y < 50)
		button_translate(map2d, 0, -1);
	if ((int)mouse.y > max_y - 50)
		button_translate(map2d, 0, 1);
}
