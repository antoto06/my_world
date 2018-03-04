/*
** EPITECH PROJECT, 2018
** test
** File description:
** maths
*/

#include "my_world.h"
#include <criterion/criterion.h>

Test(maths, vector1)
{
	sfVector2f assert = {0, 0};
	sfVector2f test = project_iso_point(0, 0, 0);

	cr_assert_eq(assert.x, test.x);
	cr_assert_eq(assert.y, test.y);
}
