/*
** EPITECH PROJECT, 2018
** text bx
** File description:
** world
*/

#include "my_world.h"

text_box_t create_text_box()
{
	text_box_t box;

	box.panel_sprt = sfSprite_create();
	box.panel_txtr = sfTexture_createFromFile("...", NULL);
	//.....

	return box;
}
