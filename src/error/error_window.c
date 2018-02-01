/*
** EPITECH PROJECT, 2018
** error
** File description:
** made by developper
*/

int check_error(int ac, char **av)
{
	if (ac != 3) {
		my_putstr("Error\n");
		return -1;
	}
	else
		return 0;
}
