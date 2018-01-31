/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** main
*/

#include "my_world.h"

int main(int ac, char **av)
{
	int map3d[MAP_X][MAP_Y] = {
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 02, 01, 00},
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00}
	};
	map_node_t **map2d = create_2d_map(map3d);
	window_t window = create_window(my_getnbr(av[1]), my_getnbr(av[2]));

	(void)ac;
	while (1) {
		sfRenderWindow_clear(window.m_window, sfBlack);
		display_vertex(window.m_window, map2d);
		sfRenderWindow_display(window.m_window);
	}
	return 0;
}
