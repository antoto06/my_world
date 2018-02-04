/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** main
*/

#include "my_world.h"

int main(int ac, char **av)
{
	input_map_t map3d = my_rd(av[3]);
	window_t window	= create_window_err(ac, av);
	map_node_t **map2d;

	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	while (sfRenderWindow_isOpen(window.m_window)) {
		while (sfRenderWindow_pollEvent(window.m_window, &window.event)) {
			analyse_event(&window, map2d);
		}
		sfRenderWindow_clear(window.m_window, sfBlack);
		display_vertex(window.m_window, map2d);
		display_button_translate(window, window.window_ui.button_translate);
		sfRenderWindow_display(window.m_window);
	}
	return 0;
}
