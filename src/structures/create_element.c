/*
** EPITECH PROJECT, 2018
** element
** File description:
** world
*/

#include "my_world.h"

element_t create_element(sfVector2f m_pos, char *path)
{
	element_t element;
	sfVector2f m_size = {20, 20};

	element.sprt = sfSprite_create();
	element.txtr = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(element.sprt, element.txtr, sfFalse);
	element.pos = pos;
	element.size = m_size;
	return element;
}
