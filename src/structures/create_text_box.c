/*
** EPITECH PROJECT, 2018
** text bx
** File description:
** world
*/

#include "my_world.h"

button_t *create_save_buttons(window_t window)
{
	button_t *buttons = malloc(sizeof(button_t) * 2);
	sfVector2f pos1 = get_position_by_percent(window, 40, 65);
	sfVector2f pos2 = get_position_by_percent(window, 60, 65);

        buttons[0] = create_button(pos1, "save", "save your map!");
        buttons[1] = create_button(pos2, "Cancel", "Back to the map");
	return buttons;
}

text_box_t create_text_box(window_t window)
{
	text_box_t box;
	sfVector2f pos_panel = get_position_by_percent(window, 30, 15);
	sfVector2f pos_txt = get_position_by_percent(window, 40, 50);

	box.stock_str = NULL;
	box.text_pos = pos_panel;
	box.panel_sprt = sfSprite_create();
	box.panel_txtr = sfTexture_createFromFile(PANEL_SAVE, NULL);
	sfSprite_setTexture(box.panel_sprt, box.panel_txtr, sfFalse);
	sfSprite_setPosition(box.panel_sprt, pos_panel);
	box.dynamic_txt = sfText_create();
	box.font = sfFont_createFromFile(FONT1);
	sfText_setPosition(box.dynamic_txt, pos_txt);
	sfText_setColor(box.dynamic_txt, sfBlue);
	sfText_setString(box.dynamic_txt, "");
	sfText_setFont(box.dynamic_txt, box.font);
	sfText_setCharacterSize(box.dynamic_txt, 20);
	box.buttons = create_save_buttons(window);
	return box;
}
