/*
** EPITECH PROJECT, 2018
** header
** File description:
** header
*/

#ifndef MY_WORLD_H
#define MY_WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <math.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <stddef.h>

#define MAP_X 6
#define MAP_Y 6
#define ANGLE_X 35
#define ANGLE_Y 25
#define SCALING_X 128
#define SCALING_Y 128
#define SCALING_Z 128

typedef struct window_s {
	sfRenderWindow *m_window;
} window_t;

sfVector2f project_iso_point(int x, int y, int z);
window_t create_window(int x, int y);

#endif
