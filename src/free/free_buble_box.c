/*
** EPITECH PROJECT, 2018
** free_buble_box
** File description:
** world
*/

#include "my_world.h"

void free_buble_box(buble_box_t item)
{
	sfText_destroy(item.message);
	sfFont_destroy(item.font);
}
