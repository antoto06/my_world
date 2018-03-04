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

void create_button_map(button_t button, sfVector2f message_pos, char *msg)
{
	sfText_setPosition(button.message, message_pos);
	sfText_setColor(button.message, sfBlue);
	sfText_setString(button.message, msg);
	sfText_setFont(button.message, button.font);
	sfText_setCharacterSize(button.message, 30);
}

void set_object(button_t *button, sfVector2f position, sfVector2f size)
{
	button->shape = sfRectangleShape_create();
	button->txtr = sfTexture_createFromFile(BUTTON_GREEN, NULL);
	sfRectangleShape_setTexture(button->shape, button->txtr, sfFalse);
	sfRectangleShape_setSize(button->shape, size);
	sfRectangleShape_setPosition(button->shape, position);
}

button_t create_button(sfVector2f position, char *msg, char *buble_str)
{
	button_t button;
	sfVector2f message_pos;
	sfVector2f size = {100, 50};

	set_object(&button, position, size);
	button.shape_hover = sfRectangleShape_create();
	button.txtr = sfTexture_createFromFile(BUTTON_GREEN_HOVER, NULL);
	sfRectangleShape_setTexture(button.shape_hover, button.txtr, sfFalse);
	sfRectangleShape_setSize(button.shape_hover, size);
	sfRectangleShape_setPosition(button.shape_hover, position);
	button.pos = position;
	message_pos.x = position.x + (size.x / 8);
	message_pos.y = position.y + (size.y / 8);
	button.size = size;
	button.font = sfFont_createFromFile(FONT1);
	button.message = sfText_create();
	create_button_map(button, message_pos, msg);
	button.buble_str = my_strcat_malloc(NULL, buble_str);
	button.hovered = sfFalse;
	return button;
}
