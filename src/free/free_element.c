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
	sfTexture_destroy(item.txtr);
}
