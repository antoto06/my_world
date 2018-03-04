/*
** EPITECH PROJECT, 2018
** element
** File description:
** world
*/

#include "my_world.h"

void display_node_elements(map_node_t *map2d,
		window_t *window, input_map_t tmp)
{
	int j = 0;

	while (j < tmp.len_y) {
		if (map2d[j].element.rendered == sfTrue) {
			sfRenderWindow_drawSprite(window->m_window,
				map2d[j].element.sprt, NULL);
		}
		j++;
	}
}
void display_elements(window_t *window, map_node_t **map2d)
{
	input_map_t tmp = window->stock_map2d[0][0].input_map;
	int i = 0;

	while (i < tmp.len_x) {
		display_node_elements(map2d[i], window, tmp);
		i++;
	}
}

void display_analizer(window_t window, visualizer_t visu)
{
	sfRenderWindow_drawSprite(window.m_window, visu.sprt, NULL);
}
