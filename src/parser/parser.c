/*
** EPITECH PROJECT, 2018
** parser
** File description:
** made by developper
*/

#include "my_world.h"

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

int nb_back(char *str)
{
	int nb_back = 0;

	while (get_next_line(str) > 0)
		nb_back++;
	return nb_back;
}

input_map_t my_str_to_int_array(char *str)
{
	input_map_t v;
	int i = 0;
	int j = 0;

	v.map = malloc(sizeof(int *) * (nb_word(str) + 1));
	while (str) {
		v.map[j] = malloc(sizeof(int) * nb_back(str));
		while (str[i] != '\0') {
			v.map[i][j] = my_getnbr(&str[i]);
			j++;
		}
		v.len_x = j;
		j = 0;
		i++;
	}
	v.len_y = i;
	return v;
}
