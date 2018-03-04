/*
** EPITECH PROJECT, 2018
** elem
** File description:
** button
*/

#include "my_world.h"

void set_map_id(map_node_t **map2d, int m_id)
{
	input_map_t tmp = map2d[0][0].input_map;
	int i = 0;
	int j = 0;

	while (i < tmp.len_x - 1) {
		while (j < tmp.len_y - 1) {
			map2d[i][j].element.id = m_id;
			j++;
		}
		j = 0;
		i++;
	}
}

void get_txtr_id(map_node_t node)
{
	if (node.element.active == sfTrue)
		return;
	sfSprite_setTexture(node.element.sprt,
		node.element.txtr[node.element.id], sfFalse);
}

void set_texture_id(map_node_t **map2d)
{
	input_map_t tmp = map2d[0][0].input_map;
	int i = 0;
	int j = 0;

	while (i < tmp.len_x - 1) {
		while (j < tmp.len_y - 1) {
			get_txtr_id(map2d[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void manage_elem(window_t *window, map_node_t **map2d,
	button_t button, sfMouseButtonEvent mouse_event)
{
	element_t tmp = map2d[0][0].element;

	if (button_is_clicked(button, mouse_event) == sfTrue
	&& tmp.id != 4) {
		set_map_id(map2d, tmp.id + 1);
	} else if (button_is_clicked(button, mouse_event) == sfTrue
	&& tmp.id == 4) {
		set_map_id(map2d, 0);
	}
	set_texture_id(map2d);
}
