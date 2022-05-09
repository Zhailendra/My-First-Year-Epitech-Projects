/*
** EPITECH PROJECT, 2021
** manage_animations
** File description:
** Function to manage game animation
*/

#include "../include/my_hunter.h"

int rev_move_rect(window_t *my_window, target_t *my_target)
{
    if (my_target->rev_target_position.x <= -200) {
        my_window->tmp = 3;
        my_printf("Fly Away\n");
        manage_score(my_window, my_target);
        my_target->rev_target_position.x = 2000;
        my_target->rev_target_position.y = rand() % 750;
    } else {
        my_target->rev_target_position.x -= 30;
        return (1);
    }
}

int move_rect(window_t *my_window, target_t *my_target)
{
    if (my_target->target_position.x >= 1920) {
        my_window->tmp = 3;
        my_printf("Fly Away\n");
        manage_score(my_window, my_target);
        my_target->target_position.x = -250;
        my_target->target_position.y = rand() % 750;
    } else {
        my_target->target_position.x += 30;
        return (1);
    }
}

void animation(window_t *my_window, target_t *my_target)
{
    my_target->time = sfClock_getElapsedTime(my_target->clock);
    my_target->velocity = my_target->time.microseconds / 1000000.0;

    if (my_target->velocity >= 0.1) {
        if (move_rect(my_window, my_target) == 1) {
            my_target->rect.left += 174;
        }
        if (rev_move_rect(my_window, my_target) == 1) {
            my_target->rev_rect.left += 174;
        }
        sfClock_restart(my_target->clock);
    }
    if (my_target->rect.left == 522)
        my_target->rect.left = 0;
    if (my_target->rev_rect.left == 522)
        my_target->rev_rect.left = 0;
}

void manage_value(target_t *my_target)
{
    my_target->rect.left = 0;
    my_target->rect.top = 0;
    my_target->rect.width = 174;
    my_target->rect.height = 115;
    my_target->rev_rect.left = 0;
    my_target->rev_rect.top = 0;
    my_target->rev_rect.width = 174;
    my_target->rev_rect.height = 115;
    my_target->velocity = 1.0;
    my_target->target_position.x = -200;
    my_target->target_position.y = 150;
    my_target->rev_target_position.x = 2000;
    my_target->rev_target_position.y = 300;
    my_target->clock = sfClock_create();
}
