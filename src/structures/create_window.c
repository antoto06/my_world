/*
** EPITECH PROJECT, 2018
** create
** File description:
** window
*/

#include "my_world.h"

void set_window_objects(window_t *window)
{
	window->window_ui = create_ui(*window);
	window->map_visible = sfTrue;
	window->buble_box = create_buble_box(*window);
	window->elem_visu = create_visualizer(*window);
}

window_t create_window(int m_x, int m_y)
{
	window_t window;
	sfVector2f m_sizef = {(float)m_x, (float)m_y};
	sfVector2u m_size;
	sfVideoMode mode_tmp = {m_x, m_y, 32};

	window.m_window = sfRenderWindow_create(mode_tmp,
			"My_World", sfClose | sfResize, NULL);
	sfRenderWindow_setFramerateLimit(window.m_window, 60);
	window.background = sfRectangleShape_create();
	sfRectangleShape_setSize(window.background, m_sizef);
	window.background_txtr = sfTexture_createFromFile(PANEL_BKGRD, NULL);
	sfRectangleShape_setTexture(window.background, window.background_txtr,
			sfFalse);
	m_size = sfRenderWindow_getSize(window.m_window);
	window.size = m_size;
	set_window_objects(&window);
	window.quit = sfFalse;
	return window;
}

window_t create_window_err(int ac, char **av)
{
	if (ac == 4)
		return create_window(my_getnbr(av[1]), my_getnbr(av[2]));
	return create_window(1920, 1080);
}
