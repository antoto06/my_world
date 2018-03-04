/*
** EPITECH PROJECT, 2018
** save
** File description:
** legend
*/

#include "my_world.h"

int check_save_dir(void)
{
	DIR *dir;

	dir = opendir("./save/");
	if (!dir) {
		closedir(dir);
		return -1;
	} else {
		closedir(dir);
		return 1;
	}
}

void do_write(int mapnb, FILE *fp)
{
	char nb;
	char space = ' ';
	char neg = '-';
	char *buff = NULL;

	if (mapnb < 0)
		fwrite(&neg, sizeof(char), 1, fp);
	buff = int_to_str(mapnb);
	nb = buff[0];
	fwrite(&nb, sizeof(char), 1, fp);
	fwrite(&space,  sizeof(char), 1, fp);
}

void write_file(int **map_z, int len_x, int len_y, FILE *fp)
{
	int i = 0;
	int j = 0;
	char ret = '\n';

	while (i < len_y) {
		while (j < len_x) {
			do_write(map_z[i][j], fp);
			j++;
		}
		fwrite(&ret, sizeof(char), 1, fp);
		j = 0;
		i++;
	}
}

void save_map(char *file_name, window_t window)
{
	FILE *fp;
	char *path = my_strcat_malloc("./save/", file_name);
	char *file_name_ext = my_strcat_malloc(path, ".legend");
	int **map_z = window.stock_map2d[0][0].input_map.map;
	int len_x = window.stock_map2d[0][0].input_map.len_x;
	int len_y = window.stock_map2d[0][0].input_map.len_y;

	if (check_save_dir() < 0) {
		my_putstr("Error: cannot find save directory\n");
		return;
	}
	fp = fopen(file_name_ext, "rb+");
	if (!fp)
		fp = fopen(file_name_ext, "wb");
	write_file(map_z, len_x, len_y, fp);
	free(path);
	free(file_name_ext);
	fclose(fp);
}
