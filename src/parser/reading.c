/*
** EPITECH PROJECT, 2018
** read
** File description:
** Made by developper
*/

input_map_t my_rd(char *str)
{
	FILE fp = fopen(str, O_RDONLY);
	char *s;

	while (s)
		fread(s, 1, 1, fp);
	return(my_str_to_int_array(s));
}

