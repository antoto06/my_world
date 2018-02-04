/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** CPE
*/

#include "get_next_line.h"
#include <fcntl.h>

int my_strlen(char *str)
{
	int i = 0;

	while (str && str[i])
		i++;
	return i;
}

char *my_strncat(char *dest, char *src, int nb)
{
	int i = 0;
	int j = 0;
	char *res;

	res = malloc(sizeof(char) * (my_strlen(dest) + nb + 1));
	if (!res)
		return NULL;
	while (dest && dest[i] != '\0') {
		res[i] = dest[i];
		i++;
	}
	while (src && (src[j] != '\0') && nb > 0) {
		res[i] = src[j];
		j++;
		i++;
		nb--;
	}
	res[i] = '\0';
	return res;
}

int get_return(char *str)
{
	int i = 0;

	while (str && str[i]) {
		if (str[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

char *get_line_in_stock(char *stock)
{
	int i = 0;
	char *line = NULL;

	while (stock && stock[i]) {
		if (stock[i] == '\n') {
			line = my_strncat(line, stock, i);
			return line;
		}
		i++;
	}
	return NULL;
}

char *get_next_line(int fd)
{
	int read_ret = 0;
	static char *stock = NULL;
	static int end = 0;
	char buffer[READ_SIZE];
	char *line = NULL;

	if (fd < 0)
		return NULL;
	while (get_return(stock) == 0 && end == 0) {
		read_ret = read(fd, buffer, READ_SIZE);
		end = (read_ret < READ_SIZE) ? 1 : 0;
		stock = my_strncat(stock, buffer, READ_SIZE);
		if (stock == NULL || read_ret <= 0)
			return NULL;
		if (end == 1 && get_return(stock) == 0)
			return stock;
	}
	line = get_line_in_stock(stock);
	stock = &stock[my_strlen(line) + 1];
	return (!line) ? NULL : line;
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *got = get_next_line(fd);

	(void)ac;
	while (got) {
		printf("%s", got);
		printf("\n");
		free(got);
		got = get_next_line(fd);
	}
}
