/*
** EPITECH PROJECT, 2018
** parser
** File description:
** made by developper
*/

#include "my_world.h"

int digit_len(char *line)
{
	int i = 0;

	while (line && line[i]) {
		if (line[i] == ' ')
			return i;
		i++;
	}
}

int nb_word(char const *str)
{
	int i = 0;
	int nb;

        nb = 1;
	while (str[i] != '\0') {
		if (str[i] <= '0' || str[i] >= '9')
			nb++;
		i++;
	}
	return (nb);
}

int nb_back(int fd)
{
	int nb_back = 0;
	char *buffer = get_next_line(fd);

	while (buffer) {
		free(buffer);
		buffer = get_next_line(fd);
		nb_back++;
	}
	return nb_back;
}

int *parse_line(char *line)
{
	int i = 0;
	int map_offset = 0;
	int *map = malloc(sizeof(int) * nb_word(line));

	while (line && line[i]) {
		if (line[i] >= '0' && line[i] <= '9') {
			map[map_offset] = my_getnbr(&line[i]);
			i = i + digit_len(&line[i]);
			map_offset++;
		}
		i++;
	}
	return map;
}

input_map_t my_str_to_int_array(char *path)
{
	int fd = open(path, O_RDONLY);
	input_map_t input_map;
	int j = 0;
	char *buffer = get_next_line(fd);

	printf("%s\n", buffer);
	input_map.map = malloc(sizeof(int *) * 12);
	while (buffer) {
		input_map.map[j] = parse_line(buffer);
		j++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	input_map.len_x = j;
	input_map.len_y = nb_back(fd);
	return input_map;
}
