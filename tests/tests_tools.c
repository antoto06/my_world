/*
** EPITECH PROJECT, 2018
** test
** File description:
** maths
*/

#include "my_world.h"
#include <criterion/criterion.h>

Test(tool, test0)
{
	window_t window = create_window_err(3, NULL);
	input_map_t map3d;
	map_node_t **map2d;

	map3d = my_rd(DEF_3DMAP);
	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	tool_elevate(&window, 0, 0, map2d);
	cr_assert_eq(window.stock_map2d[0][0].input_map.map[0][0], 1);
}

Test(tool, test1)
{
	window_t window = create_window_err(3, NULL);
	input_map_t map3d;
	map_node_t **map2d;

	map3d = my_rd(DEF_3DMAP);
	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	window.window_ui.tools_state.corner = sfFalse;
	tool_elevate(&window, 0, 0, map2d);
	cr_assert_eq(window.stock_map2d[0][0].input_map.map[0][0], 1);
}


Test(tool, test2)
{
	window_t window = create_window_err(3, NULL);
	input_map_t map3d;
	map_node_t **map2d;

	map3d = my_rd(DEF_3DMAP);
	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	tool_dig(&window, 0, 0, map2d);
	cr_assert_eq(window.stock_map2d[0][0].input_map.map[0][0], -1);
}

Test(tool, test3)
{
	window_t window = create_window_err(3, NULL);
	input_map_t map3d;
	map_node_t **map2d;

	map3d = my_rd(DEF_3DMAP);
	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	window.window_ui.tools_state.corner = sfFalse;
	tool_dig(&window, 0, 0, map2d);
	cr_assert_eq(window.stock_map2d[0][0].input_map.map[0][0], -1);
}


Test(tool, test4)
{
	window_t window = create_window_err(3, NULL);
	input_map_t map3d;
	map_node_t **map2d;

	map3d = my_rd(DEF_3DMAP);
	map2d = create_2d_map(map3d, window);
	generate_texture(map2d);
	tool_elem(&window, 0, 0, map2d);
	if (map2d[0][0].element.active == sfFalse)
		cr_assert_fail();
	map2d[0][0].element.active = sfFalse;
	manage_elem_display(window, &map2d[0][0]);
	if (map2d[0][0].element.rendered == sfTrue)
		cr_assert_fail();
	window.window_ui.tools_state.element = sfFalse;
	manage_elem_display(window, &map2d[0][0]);
	map2d[0][0].element.active = sfFalse;
	manage_elem_display(window, &map2d[0][0]);
}
