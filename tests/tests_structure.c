/*
** EPITECH PROJECT, 2018
** test
** File description:
** maths
*/

#include "my_world.h"
#include <criterion/criterion.h>

Test(structure, test0)
{
	window_t window = create_window_err(3, NULL);
	input_map_t map3d;
	map_node_t **map2d;

	if (!window.m_window)
		cr_assert_fail();
	map3d = my_rd("save/test.legend");
	if (!map3d.map)
		cr_assert_fail();
	map2d = create_2d_map(map3d, window);
	if (!map2d)
		cr_assert_fail();
	generate_texture(map2d);
	if (!map2d[0][0].convex_points)
		cr_assert_fail();
}

Test(structure, test1)
{
	char *av[] = {"./my_world", "1920", "1080", "data"};
	window_t window = create_window_err(4, av);

	if (!window.m_window)
		cr_assert_fail();
}

Test(structure, test2)
{
	char *av[] = {"./my_world", "1920", "1080", "data"};
	window_t window = create_window_err(4, av);

	change_button_message(window.window_ui.button_translate[0],
		"new_msg");
	cr_assert_str_neq(window.window_ui.button_translate[0].message,
		"new_msg");
	change_button_texture(window.window_ui.button_translate[0],
		BUTTON_GREEN_BURN);
}
