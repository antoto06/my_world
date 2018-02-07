/*
** EPITECH PROJECT, 2018
** button
** File description:
** init
*/

#include "my_world.h"

void change_button_message(button_t button, char *new_msg)
{
	sfText_setString(button.message, new_msg);
}

void change_button_texture(button_t button, char *new_txtr)
{
	button.txtr = sfTexture_createFromFile(new_txtr, NULL);
	sfRectangleShape_setTexture(button.shape, button.txtr, sfFalse);
}

button_t create_button(sfVector2f position, char *msg)
{
	button_t button;
	sfVector2f message_pos;
	sfVector2f size = {100, 50};

	button.shape = sfRectangleShape_create();
	button.txtr = sfTexture_createFromFile(BUTTON_GREEN, NULL);
	sfRectangleShape_setTexture(button.shape, button.txtr, sfFalse);
	sfRectangleShape_setSize(button.shape, size);
	sfRectangleShape_setPosition(button.shape, position);
	button.pos = position;
	message_pos.x = position.x + (size.x / 8);
	message_pos.y = position.y + (size.y / 8);
	button.size = size;
	button.font = sfFont_createFromFile(FONT1);
	button.message = sfText_create();
	sfText_setPosition(button.message, message_pos);
	sfText_setColor(button.message, sfBlue);
	sfText_setString(button.message, msg);
	sfText_setFont(button.message, button.font);
	sfText_setCharacterSize(button.message, 30);
	return button;
}
