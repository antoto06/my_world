/*
** EPITECH PROJECT, 2018
** load
** File description:
** world
*/

#include "my_world.h"

int check_directory(char *file)
{
	DIR *dir;
	struct dirent *dir_prop;

	dir = opendir("./save/");
	if (dir == NULL)
		return -1;
	dir_prop = readdir(dir);
	while (dir_prop) {
		if (my_strcmp(dir_prop->d_name, file) == 0)
			return 1;
		dir_prop = readdir(dir);
	}
	closedir(dir);
	return -1;
}

char *get_file_extend(char *path)
{
	char *prev;
	char *extend = NULL;
	int has_extend = 0;

	for (int i = 0; path && path[i]; i++) {
		if (my_strcmp(&path[i], ".legend") == 0)
			has_extend = 1;
	}
	if (has_extend == 0) {
		prev = my_strcat_malloc(path, ".legend");
		if (check_directory(prev) > 0) {
			extend = my_strcat_malloc("./save/", prev);
			free(prev);
			return extend;
		}
		free(prev);
	}
	return NULL;
}

int load_new_map(char *new_map_path, window_t *window)
{
	input_map_t map3d;
	map_node_t **new_map;
	char *file_extented = get_file_extend(new_map_path);

	if (!file_extented) {
		my_putstr("Incorrect file\n");
		return - 1;
	}
	map3d = my_rd(file_extented);
	new_map = create_2d_map(map3d, *window);
	generate_texture(new_map);
	window->stock_map2d = NULL;
	window->stock_map2d = new_map;
	free(file_extented);
	return 0;
}
