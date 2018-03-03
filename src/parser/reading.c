/*
** EPITECH PROJECT, 2018
** read
** File description:
** Made by developper
*/

#include "my_world.h"

int check_valid_file(char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd < 0 || !fd)
		return -1;
	return 1;
}

input_map_t my_rd(char *path)
{
	input_map_t input;
	int error = check_valid_file(path);

	printf("open %s\n", path);
	if (error == -1) {
		input.error = -1;
		return input;
	}
	input = my_str_to_int_array(path);
	return input;
}

