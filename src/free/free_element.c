/*
** EPITECH PROJECT, 2018
** free
** File description:
** element
*/

#include "my_world.h"

void free_element(element_t item)
{
	sfSprite_destroy(item.sprt);
	for (int i = 0; i < 2; i++)
		sfTexture_destroy(item.txtr[i]);
}
