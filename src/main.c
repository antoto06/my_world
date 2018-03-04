/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** main
*/

#include "my_world.h"

void my_world(input_map_t map3d, window_t window)
{
	map_node_t **map2d;
	sfMusic *music = sfMusic_createFromFile(SONG_BACK);

	sfMusic_play(music);
	sfMusic_setLoop(music, sfTrue);
	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	window.stock_map2d = map2d;
	while (sfRenderWindow_isOpen(window.m_window)
	&& window.quit == sfFalse) {
		while (sfRenderWindow_pollEvent(window.m_window,
					&window.event)) {
			analyse_event(&window, window.stock_map2d);
		}
		sfRenderWindow_clear(window.m_window, sfBlack);
		display_tree(&window);
		sfRenderWindow_display(window.m_window);
	}
	sfMusic_destroy(music);
	free_all(window, map2d);
}

void launcher(int ac, char **av)
{
	input_map_t map3d;
	window_t window;

	if (ac == 1) {
		map3d = my_rd(DEF_3DMAP);
		if (map3d.error == -1)
			return;
		window = create_window_err(ac, av);
		my_world(map3d, window);
	} else if (ac == 4) {
		map3d = my_rd(av[3]);
		if (map3d.error == -1)
			return;
		window = create_window_err(ac, av);
		my_world(map3d, window);
	} else {
		print_help();
	}
}

int main(int ac, char **av, char **env)
{
	if (env == NULL)
		return 84;
	if (ac == 2 && my_strcmp(av[1], "-h") == 0)
		print_help();
	else
		launcher(ac, av);
	return 0;
}
