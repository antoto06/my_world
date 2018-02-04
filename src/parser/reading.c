/*
** EPITECH PROJECT, 2018
** read
** File description:
** Made by developper
*/

#include "my_world.h"

input_map_t my_rd(char *str)
{
	int fd = open(str, O_RDONLY);
	char *s = get_next_line(fd);

	while (s = get_next_line(fd));
	return (my_str_to_int_array(s));
}

