/*
** EPITECH PROJECT, 2021
** display.C
** File description:
** display my_hunter's window
*/

#include "../include/my_hunter.h"

void display_targets(window_t *my_window, target_t *my_target,
weapon_t *my_weapon)
{
    sfSprite_setTextureRect(my_target->target_sprite, my_target->rect);
    sfRenderWindow_drawSprite(my_window->window, my_target->target_sprite,
    NULL);
    sfSprite_setPosition(my_target->target_sprite, my_target->target_position);
    sfSprite_setTextureRect(my_target->rev_target_sprite,
    my_target->rev_rect);
    sfRenderWindow_drawSprite(my_window->window, my_target->rev_target_sprite,
    NULL);
    sfSprite_setPosition(my_target->rev_target_sprite,
    my_target->rev_target_position);
    sfRenderWindow_drawSprite(my_window->window, my_weapon->weapon_sprite,
    NULL);
    sfSprite_setPosition(my_weapon->weapon_sprite, my_weapon->weapon_position);
}

void display_game(window_t *my_window, target_t *my_target,
weapon_t *my_weapon)
{
    sfRenderWindow_clear(my_window->window, sfBlack);
    sfRenderWindow_drawSprite(my_window->window, my_window->font_sprite, NULL);
    sfRenderWindow_drawText(my_window->window, my_window->my_score, NULL);
    display_targets(my_window, my_target, my_weapon);
    sfRenderWindow_drawText(my_window->window, my_window->my_score, NULL);
    sfRenderWindow_drawSprite(my_window->window, my_window->score_sprite,
    NULL);
    sfSprite_setPosition(my_window->hearths_sprite, (sfVector2f) {200, 850});
    sfRenderWindow_drawSprite(my_window->window, my_window->hearths_sprite,
    NULL);
    sfRenderWindow_display(my_window->window);
}
