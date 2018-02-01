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
		{00, 00, 00, -1, 00, 00, 01, 02, 02, 03, 02},
		{00, 00, -1, -1, -1, 00, 01, 02, 03, 03, 02},
		{00, 00, 00, -1, 00, 00, 00, 01, 02, 02, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00}
	};
	window_t window = create_window(my_getnbr(av[1]), my_getnbr(av[2]));
	map_node_t **map2d = create_2d_map(map3d, window);
	sfVector2f button1_pos = {500, 500};
	button_t button1 = create_button(button1_pos, "button");

	generate_texture(map2d);
	(void)ac;
	while (sfRenderWindow_isOpen(window.m_window)) {
		while (sfRenderWindow_pollEvent(window.m_window, &window.event)) {
			analyse_event(&window, map2d);
			if (window.event.type == sfEvtMouseButtonPressed) {
				printf("clicked\n");
				if (button_is_clicked(button1, window.event.mouseButton) == sfTrue)
				    printf("button\n");
			}
		}
		sfRenderWindow_clear(window.m_window, sfBlack);
		display_vertex(window.m_window, map2d);
		display_button(window, button1);
		sfRenderWindow_display(window.m_window);
	}
	return 0;
}
