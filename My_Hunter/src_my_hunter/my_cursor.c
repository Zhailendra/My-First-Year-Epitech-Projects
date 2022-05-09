/*
** EPITECH PROJECT, 2021
** my_cursor
** File description:
** Functions to manage my cursor
*/

#include "../include/my_hunter.h"

void set_weapon(window_t *my_window, weapon_t *my_weapon)
{
    sfVector2i weapon = sfMouse_getPositionRenderWindow(my_window->window);
    my_weapon->weapon_position.x = (float) weapon.x - 48;
    my_weapon->weapon_position.y = (float) weapon.y - 46;
    sfRenderWindow_setMouseCursorVisible(my_window->window, sfFalse);
}

void tool_function(window_t *my_window)
{
    my_window->chances--;
    if (my_window->chances == 0)
        my_window->tmp = 3;
}

void manage_mouse_click(window_t *my_window, target_t *my_target)
{
    my_window->tmp = 0;
    sfVector2i cursor = sfMouse_getPositionRenderWindow(my_window->window);

    if (cursor.x >= my_target->target_position.x &&
    cursor.x <= my_target->target_position.x + 174 &&
    cursor.y >= my_target->target_position.y &&
    cursor.y <= my_target->target_position.y + 115)
        my_window->tmp = 1;
    else if (cursor.x >= my_target->rev_target_position.x &&
    cursor.x <= my_target->rev_target_position.x + 174 &&
    cursor.y >= my_target->rev_target_position.y &&
    cursor.y <= my_target->rev_target_position.y + 115)
        my_window->tmp = 2;
    else
        tool_function(my_window);
    manage_score(my_window, my_target);
}
