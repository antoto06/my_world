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
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 01, 01, 00, 00, 00, 00, 00, 01, 00, 00},
		{00, 01, 01, 00, 00, 00, 00, 01, 01, 02, 00},
		{00, 00, 00, 00, 00, 00, 01, 01, 02, 03, 00},
		{00, 00, 00, 00, 00, 00, 01, 02, 02, 03, 02},
		{00, 00, 00, 00, 00, 00, 01, 02, 03, 03, 02},
		{00, 00, 00, 00, 00, 00, 00, 01, 02, 02, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00}
	};
	window_t window = create_window(my_getnbr(av[1]), my_getnbr(av[2]));
	map_node_t **map2d = create_2d_map(map3d, window);

	(void)ac;
	while (1) {
		sfRenderWindow_clear(window.m_window, sfBlack);
		display_vertex(window.m_window, map2d);
		sfRenderWindow_display(window.m_window);
	}
	return 0;
}
