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

sfTexture **get_texture_array(void)
{
	sfTexture **array;

	array = malloc(sizeof(sfTexture *) * 5);
	array[0] = sfTexture_createFromFile(ELEMENT_T1, NULL);
	array[1] = sfTexture_createFromFile(ELEMENT_H1, NULL);
	array[2] = sfTexture_createFromFile(ELEMENT_H2, NULL);
	array[3] = sfTexture_createFromFile(ELEMENT_O1, NULL);
	array[4] = sfTexture_createFromFile(ELEMENT_O2, NULL);
	return array;
}

element_t create_element(sfVector2f m_pos)
{
	element_t element;
	sfVector2f m_size = {20, 20};

	element.sprt = sfSprite_create();
	element.txtr = get_texture_array();
	element.pos.x = m_pos.x - 40;
	element.pos.y = m_pos.y - 40;
	sfSprite_setPosition(element.sprt, element.pos);
	element.active = sfFalse;
	element.rendered = sfFalse;
	element.size = m_size;
	element.id = 0;
	return element;
}
