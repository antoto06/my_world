/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** main
*/

#include "my_world.h"

int main(void)
{
	int map3d[MAP_X][MAP_Y] = {
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00}
	};
	sfVector2f **map2d = create_2d_map(map3d);
	sfRenderWindow *window;
	sfVideoMode mode = {1920, 1080, 32};

	window = sfRenderWindow_create(mode, "My_world",
			sfClose | sfResize, NULL);
	while (1) {
		sfRenderWindow_clear(window, sfBlack);
		display_vertex(window, map2d);
		sfRenderWindow_display(window);
	}
	return 0;
}
