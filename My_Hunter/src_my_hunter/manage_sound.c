/*
** EPITECH PROJECT, 2021
** manage_sound
** File description:
** Functions to manage sounds of my game
*/

#include "../include/my_hunter.h"

void set_sound(window_t *my_window, sound_t *my_sound)
{
    my_sound->soundbuff = sfSoundBuffer_createFromFile
    ("ressources/font-theme.wav");
    my_sound->sound = sfSound_create();
    sfSound_setBuffer(my_sound->sound, my_sound->soundbuff);
    sfSound_setLoop(my_sound->sound, sfTrue);
    sfSound_play(my_sound->sound);
}
