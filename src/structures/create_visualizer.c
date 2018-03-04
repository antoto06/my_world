/*
** EPITECH PROJECT, 2018
** visualizer
** File description:
** world
*/

#include "my_world.h"


visualizer_t create_visualizer(window_t window)
{
	visualizer_t visu;
	sfVector2f pos = get_position_by_percent(window, 23, 2);

	visu.sprt = sfSprite_create();
	visu.txtr = sfTexture_createFromFile(ELEMENT_H1, NULL);
	sfSprite_setTexture(visu.sprt, visu.txtr, sfFalse);
	sfSprite_setPosition(visu.sprt, pos);
	return visu;
}
