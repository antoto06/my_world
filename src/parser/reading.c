/*
** EPITECH PROJECT, 2018
** read
** File description:
** Made by developper
*/

#include "my_world.h"

input_map_t my_rd(char *str)
{
	FILE *fp = fopen(str, "r");
	char s[1024];

<<<<<<< HEAD
	while (fread(s, 1, 1, fp));
	return (my_str_to_int_array(s, fp));
=======
	while (s)
		fread(s, 1, 1, fp);
	return (my_str_to_int_array(s));
>>>>>>> cef05de8e4f779453e1bd664e800593925324eaf
}

