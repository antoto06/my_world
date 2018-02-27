/*
** EPITECH PROJECT, 2018
** help
** File description:
** world
*/

#include "my_world.h"

void print_help(void)
{
	my_putstr("USAGE:\n");
	my_putstr("\t./my_world [map_size_x, map_size_y]");
	my_putstr(" [map_file (.legend)]\n");
	my_putstr("Default:\n");
	my_putstr("\t ./my_world [1920, 1080] [auto generated map]\n");
}
