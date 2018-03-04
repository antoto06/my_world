/*
** EPITECH PROJECT, 2018
** element
** File description:
** world
*/

#include "my_world.h"

void set_elem_hight(sfVector2f iso, element_t *item)
{
	item->pos.x = iso.x - 40;
	item->pos.y = iso.y - 40;
	sfSprite_setPosition(item->sprt, item->pos);
}

element_t create_element(sfVector2f m_pos, char *path)
{
	element_t element;
	sfVector2f m_size = {20, 20};

	element.sprt = sfSprite_create();
	element.txtr = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(element.sprt, element.txtr, sfFalse);
	element.pos.x = m_pos.x - 40;
	element.pos.y = m_pos.y - 40;
	sfSprite_setPosition(element.sprt, element.pos);
	element.active = sfFalse;
	element.rendered = sfFalse;
	element.size = m_size;
	return element;
}
