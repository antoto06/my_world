/*
** EPITECH PROJECT, 2018
** error
** File description:
** world
*/

#include "../../include/my_world.h"

int check_error(int ac, char **av)
{
	(void)av;
	if (ac != 4) {
		my_putstr("Error\n");
		return -1;
	} else
		return 0;
}
