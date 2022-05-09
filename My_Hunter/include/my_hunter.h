/*
** EPITECH PROJECT, 2021
** my_hunter.h
** File description:
** ".h", tool functions for my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "my_printf.h"

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

void my_printf(char *string, ...);

char *my_int_to_str(int n);

void sprite_creation(window_t *my_window, target_t *my_target,
weapon_t *my_weapon);

void font_creation(window_t *my_window);

void target_creation(target_t *my_target);

void set_score(window_t *my_window);

void set_score(window_t *my_window);

void display_game(window_t *my_window, target_t *my_target,
weapon_t *my_weapon);

void display_targets(window_t *my_window, target_t *my_target,
weapon_t *my_weapon);

void manage_value(target_t *my_target);

void animation(window_t *my_window, target_t *my_target);

void set_weapon(window_t *my_window, weapon_t *my_weapon);

void analyse_events(window_t *my_window, target_t *my_target,
weapon_t *my_weapon, sfEvent event);

void manage_mouse_click(window_t *my_window, target_t *my_target);

void manage_score(window_t *my_window, target_t *my_target);

void manage_lifes(window_t *my_window);

void set_sound(window_t *my_window, sound_t *my_sound);

#endif
