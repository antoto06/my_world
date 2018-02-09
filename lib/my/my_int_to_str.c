/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my
*/

int digit_len_str(int nb)
{
	int i = 0;

	while (nb != 0) {
		nb /= 10;
		i++;
	}
	return i;
}

char *int_to_str(int nb)
{
	char *str = malloc(sizeof(char *) * digit_len_str(nb) + 1);
	int i = 0;

	if (nb == 0) {
		str[i] = '0';
		i++;
	}
	while (nb != 0) {
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	str[i] = '\0';
	str = my_revstr(str);
	return str;
}
