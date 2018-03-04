/*
** EPITECH PROJECT, 2018
** test
** File description:
** maths
*/

#include "my_world.h"
#include <criterion/criterion.h>

Test(error, test0)
{
	int ac = 1;
	int ac2 = 4;
	char **av = NULL;
	int res = check_error(ac, av);
	int res2 = check_error(ac2, av);

	cr_assert_eq(res, -1);
	cr_assert_eq(res2, 0);
	print_help();
}

Test(error, test1)
{
	int ac = 1;
	int res = check_valid_file("invalid");
	input_map_t map = my_rd("invalid");

	cr_assert_eq(res, -1);
	cr_assert_eq(map.error, -1);
}

Test(error, test2)
{
	int ac = check_directory("invalid");
	int load_err = load_new_map(NULL, NULL);

	cr_assert_eq(ac, -1);
	cr_assert_eq(load_err, -1);
}
