/*
** EPITECH PROJECT, 2018
** buble box
** File description:
** world
*/

#include "my_world.h"

sfVector2f get_optimized_size(window_t window)
{
	sfVector2f size = {100, 50};

	return size;
}

buble_box_t create_buble_box(window_t window)
{
	buble_box_t box;
	sfVector2f size = get_optimized_size(window);
	sfVector2f def_pos = {0, 0};
	sfVector2f message_pos;

	box.shape = sfRectangleShape_create();
	box.txtr = sfTexture_createFromFile(HOVER_MOUSE, NULL);
	sfRectangleShape_setTexture(box.shape, box.txtr, sfFalse);
	sfRectangleShape_setSize(box.shape, size);
	sfRectangleShape_setPosition(box.shape, def_pos);
	box.pos = def_pos;
	message_pos.x = def_pos.x + (size.x / 8);
	message_pos.y = def_pos.y + (size.y / 8);
	box.font = sfFont_createFromFile(FONT1);
	box.message = sfText_create();
	sfText_setPosition(box.message, message_pos);
	sfText_setColor(box.message, sfBlue);
	sfText_setString(box.message, "empty");
	sfText_setFont(box.message, box.font);
	sfText_setCharacterSize(box.message, 30);
	return box;
}
