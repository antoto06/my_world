/*
** EPITECH PROJECT, 2018
** button
** File description:
** init
*/

#include "my_world.h"

button_t create_button(sfVector2f position, char *msg)
{
	button_t button;
	sfVector2f size = {100, 50};

	button.shape = sfRectangleShape_create();
	button.txtr = sfTexture_createFromFile(BUTTON_GREEN, NULL);
	sfRectangleShape_setTexture(button.shape, button.txtr, sfFalse);
	sfRectangleShape_setSize(button.shape, size);
	sfRectangleShape_setPosition(button.shape, position);
	button.font = sfFont_createFromFile(FONT1);
	button.message = sfText_create();
	sfText_setPosition(button.message, position);
	sfText_setColor(button.message, sfBlue);
	sfText_setString(button.message, msg);
	sfText_setFont(button.message, button.font);
	sfText_setCharacterSize(button.message, 30);
	return button;
}
