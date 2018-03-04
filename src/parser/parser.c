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
	return 0;
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

int get_nblines(char *av)
{
	FILE *file;
	char *str = NULL;
	int read = 1;
	size_t lines_nb = 0;
	size_t len;

	file = fopen(av, "r");
	while (read != -1) {
		read = getline(&str, &len, file);
		lines_nb++;
	}
	if (str)
		free(str);
	fclose(file);
	return lines_nb - 1;
}

int *parse_line(char *line)
{
	int i = 0;
	int *map = malloc(sizeof(int) * nb_word(line));
	char **line_tab = my_str_to_word_array(line);

	while (line_tab && line_tab[i]) {
		map[i] = my_getnbr(line_tab[i]);
		i++;
	}
	map[i] = 0;
	for (int k = 0; line_tab && line_tab[k]; k++)
		free(line_tab[k]);
	free(line_tab);
	return map;
}

input_map_t my_str_to_int_array(char *path)
{
	int nb_line = get_nblines(path);
	FILE *fd = fopen(path, "r");
	input_map_t input_map;
	int j = 0;
	char *buffer = NULL;
	size_t len = 0;
	int read = 1;

	input_map.map = malloc(sizeof(int *) * nb_line);
	while (j < nb_line && read != -1) {
		read = getline(&buffer, &len, fd);
		input_map.map[j] = parse_line(buffer);
		j++;
	}
	input_map.len_x = j;
	input_map.len_y = nb_line;
	input_map.error = 0;
	fclose(fd);
	return input_map;
}
