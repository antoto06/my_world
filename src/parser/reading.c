/*
** EPITECH PROJECT, 2018
** read
** File description:
** Made by developper
*/

#include "my_world.h"

input_map_t my_rd(char *path)
{
	input_map_t input = my_str_to_int_array(path);

	return input;
}

