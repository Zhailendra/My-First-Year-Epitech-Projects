/*
** EPITECH PROJECT, 2021
** sprite_creation.c
** File description:
** Functions to create sprite then set them
*/

#include "../include/my_hunter.h"

void weapon_creation(weapon_t *my_weapon)
{
    my_weapon->weapon = sfTexture_createFromFile("ressources/weapon.png",
    NULL);
    my_weapon->weapon_sprite = sfSprite_create();

    sfSprite_setTexture(my_weapon->weapon_sprite, my_weapon->weapon, sfTrue);
    sfSprite_setPosition(my_weapon->weapon_sprite, my_weapon->weapon_position);
}

void target_creation(target_t *my_target)
{
    my_target->target = sfTexture_createFromFile("ressources/target1.png",
    NULL);
    my_target->target_sprite = sfSprite_create();
    my_target->rev_target = sfTexture_createFromFile("ressources/target2.png",
    NULL);
    my_target->rev_target_sprite = sfSprite_create();

    sfSprite_setTexture(my_target->target_sprite, my_target->target, sfTrue);
    sfSprite_setPosition(my_target->target_sprite, my_target->target_position);
    sfSprite_setTexture(my_target->rev_target_sprite, my_target->rev_target,
    sfTrue);
    sfSprite_setPosition(my_target->rev_target_sprite,
    my_target->rev_target_position);
}

void font_creation(window_t *my_window)
{
    my_window->font = sfTexture_createFromFile("ressources/my_forest.jpeg",
    NULL);
    my_window->font_sprite = sfSprite_create();
    my_window->score_font = sfTexture_createFromFile("ressources/score.png",
    NULL);
    my_window->score_sprite = sfSprite_create();
    my_window->hearths = sfTexture_createFromFile("ressources/lifes.png",
    NULL);
    my_window->hearths_sprite = sfSprite_create();

    sfSprite_setTexture(my_window->font_sprite, my_window->font, sfTrue);
    sfSprite_setTexture(my_window->score_sprite, my_window->score_font,
    sfTrue);
    sfSprite_setTexture(my_window->hearths_sprite, my_window->hearths,
    sfTrue);
    sfSprite_setTextureRect(my_window->hearths_sprite,
    (sfIntRect) {0, 0, 190, 41});
}

void sprite_creation(window_t *my_window, target_t *my_target,
weapon_t *my_weapon)
{
    font_creation(my_window);
    target_creation(my_target);
    weapon_creation(my_weapon);
}
