/*
** EPITECH PROJECT, 2018
** save
** File description:
** legend
*/

#include "my_world.h"

void write_file(int **map_z, int len_x, int len_y, FILE *fp)
{
	int i = 0;
	int j = 0;

	while (i < len_y) {
		while (j < len_x) {
			fwrite(int_to_str(map_z[i][j]), sizeof(char), 1, fp);
			fwrite(" ", sizeof(char), 1, fp);
			j++;
		}
		fwrite("\n", sizeof(char), 1, fp);
		j = 0;
		i++;
	}
}

void save_map(char *file_name, window_t window)
{
	FILE *fp;
	char *file_name_ext = my_strcat_malloc(file_name, ".legend");
	int **map_z = window.stock_map2d[0][0].input_map.map;
	int len_x = window.stock_map2d[0][0].input_map.len_x;
	int len_y = window.stock_map2d[0][0].input_map.len_y;

	fp = fopen(file_name_ext, "rb+");
	if (!fp)
		fp = fopen(file_name_ext, "wb");
	write_file(map_z, len_x, len_y, fp);
}
