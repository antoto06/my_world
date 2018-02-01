/*
** EPITECH PROJECT, 2018
** read
** File description:
** Made by developper
*/

void	my_rd(char *str)
{
	int fd = open(str, O_RDONLY);
	char *s;

	while (s) {
		free (s);
		s = get_next_line(fd);
	}
	my_str_to_word_array(s);
}

