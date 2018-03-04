/*
** EPITECH PROJECT, 2018
** test
** File description:
** maths
*/

#include "my_world.h"
#include <criterion/criterion.h>

Test(load_save, test0, .exit_code = 0)
{
	window_t window = create_window_err(3, NULL);
	input_map_t map3d;
	map_node_t **map2d;

	map3d = my_rd(DEF_3DMAP);
	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	load_new_map("test", &window);
}
