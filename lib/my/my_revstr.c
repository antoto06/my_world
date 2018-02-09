/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
	int i;
	int lenght = my_strlen(str);
	char result[lenght + 1];

	for (i = 0; i < lenght; i++) {
		result[i] = str[lenght - 1 - i];
	}
	for (i = 0; i < lenght; i++) {
		str[i] = result[i];
	}
	return (str);
}
