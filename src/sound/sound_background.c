/*
** EPITECH PROJECT, 2018
** sound
** File description:
** Made By Dev
*/

#include "my_world.h"

void sound_background()
{
	sfMusic* music_back;

	music_back = sfMusic_createFromFile(SONG_BACK);
	sfMusic_play(music_back);
}
