/*
** EPITECH PROJECT, 2018
** iso
** File description:
** projection
*/

#include "my_world.h"

sfVector2f project_iso_point(int x, int y, int z)
{
	printf("");
	sfVector2f projection;
	float angle_x_rad = ANGLE_X * M_PI / 180;
	float angle_y_rad = ANGLE_Y * M_PI / 180;

	projection.x = cos(angle_x_rad) * x - cos(angle_x_rad) * y;
	projection.y = sin(angle_y_rad) * y + sin(angle_y_rad) * x - z;
	return projection;
}
