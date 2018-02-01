/*
** EPITECH PROJECT, 2018
** parser
** File description:
** made by developper
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int get_sign(char *str)
{
	int i = 0;
	int neg = 0;

	while (str && str[i]) {
		if (str[i] == '-')
			neg++;
		i++;
	}
	if (neg % 2 == 0)
		return 1;
	else
		return 0;
}

int get_sign_num(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else if (c == '-' || c == '+')
		return 2;
	else
		return 0;
}

int my_getnbr(char *str)
{
	int i = 0;
	int nb = 0;

	if (!str)
		return 0;
	while (get_sign_num(str[i]) == 2)
		i++;
	while (get_sign_num(str[i]) == 1) {
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (get_sign(str) == 0)
		nb *= -1;
	return nb;
}

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

int	strlen(char const *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] && str[i] != ' ') {
		nb++;
		i++;
	}
	return (nb);
}

input_map_t my_str_to_word_array(char const *str)
{
	input_map_t v;
	int **tab;
	int i = 0;
	int j = 0;
	int a = 0;

	v.map = malloc(sizeof(int *) * (nb_word(str) + 1));
	while (str) {
		v.map[j] = malloc(sizeof(int) * (strlen(str) + 1));
		while (str[i] != '\0') {
			v.map[j][a] = my_getnbr(str[i]);
			a++;
			i++;
		}
		j++;
		a = 0;
		v.len_Y++;
	}
	return v;
}


int main(int ac, char **av)
{
	int **tab;
	int i = 0;
	
	if (ac < 2)
		return(0);
	else {
		tab = my_str_to_word_array(av[1]);
		while (tab[i] != '\0') {
			printf(tab);
			i++;
		}
	}
	return(0);
}
