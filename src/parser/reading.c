/*
** EPITECH PROJECT, 2018
** read
** File description:
** Made by developper
*/

void	my_rd(char *str)
{
	FILE fp = fopen(str, O_RDONLY);
	char *s;

	while (s)
		fread(s, 1, 1, fp);
	my_str_to_word_array(s);
}

