/*
** EPITECH PROJECT, 2018
** iso
** File description:
** projection
*/

#include "my_world.h"

sfVector2f quick_projection_iso_point(sfVector2f point_to_project, int z)
{
	return project_iso_point(point_to_project.y * SCALING_X,
			point_to_project.x * SCALING_Y,
			z  * SCALING_Z);
}

sfVector2f project_iso_point(int x, int y, int z)
{
	sfVector2f projection;
	float angle_x_rad = ANGLE_X * M_PI / 180;
	float angle_y_rad = ANGLE_Y * M_PI / 180;

	projection.x = cos(angle_x_rad) * x - cos(angle_x_rad) * y;
	projection.y = sin(angle_y_rad) * y + sin(angle_y_rad) * x - z;
	return projection;
}
