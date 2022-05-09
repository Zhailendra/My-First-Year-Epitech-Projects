/*
** EPITECH PROJECT, 2021
** manage_score
** File description:
** Functions to manage the final score
*/

#include "../include/my_hunter.h"

void set_score(window_t *my_window)
{
    my_window->my_score = sfText_create();
    my_window->background = sfFont_createFromFile
    ("ressources/police.ttf");
    sfText_setString(my_window->my_score, my_int_to_str(my_window->score));
    sfText_setCharacterSize(my_window->my_score, 45);
    sfText_setColor(my_window->my_score, sfWhite);
    sfText_setFont(my_window->my_score, my_window->background);
    sfText_setPosition(my_window->my_score, (sfVector2f) {1700, 850});
    my_window->timer = sfClock_create();
    sfSprite_setPosition(my_window->score_sprite, (sfVector2f) {1450, 845});
}

void display_score(window_t *my_window)
{
    if (my_window->life == 0) {
        my_printf("%d\n", my_window->score);
        my_printf("GAME OVER\n");
        sfRenderWindow_close(my_window->window);
    }
}

void manage_score(window_t *my_window, target_t *my_target)
{
    if (my_window->tmp == 1) {
        my_target->target_position.x = -250;
        my_target->target_position.y = rand() % 750;
        my_printf("HIT, score +1\n");
        my_window->score++;
    }
    if (my_window->tmp == 2) {
        my_target->rev_target_position.x = 2200;
        my_target->rev_target_position.y = rand() % 750;
        my_printf("HIT, score +1\n");
        my_window->score++;
    }
    if (my_window->tmp == 3) {
        my_window->life--;
        my_window->chances = 3;
        manage_lifes(my_window);
    }
    display_score(my_window);
}
