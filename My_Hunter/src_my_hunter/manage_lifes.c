/*
** EPITECH PROJECT, 2021
** manage_lifes.c
** File description:
** Function to manage player's health
*/

#include "../include/my_hunter.h"

void manage_lifes(window_t *my_window)
{
    int number_of_hearths = 0;

    sfIntRect rect = sfSprite_getTextureRect(my_window->hearths_sprite);
    number_of_hearths = rect.top + 42;
    sfSprite_setTextureRect(my_window->hearths_sprite, (sfIntRect)
    {0, number_of_hearths, 190, 41});
}
