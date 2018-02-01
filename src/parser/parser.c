/*
** EPITECH PROJECT, 2018
** parser
** File description:
** made by developper
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my_world.h"

int     nb_word(char const *str)
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

input_map_t my_str_to_word_array(char *str)
{
	input_map_t v;
	int i = 0;
	int j = 0;

	v.map = malloc(sizeof(int *) * (nb_word(str) + 1));
	while (str) {
		v.map[j] = malloc(sizeof(int) * (my_strlen(str) + 1));
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
