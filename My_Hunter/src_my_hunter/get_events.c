/*
** EPITECH PROJECT, 2021
** get_events
** File description:
** Functions to gest events
*/

#include "../include/my_hunter.h"

void analyse_events(window_t *my_window, target_t *my_target,
weapon_t *my_weapon, sfEvent event)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(my_window->window);
    if (event.type == sfEvtMouseButtonReleased)
        manage_mouse_click(my_window, my_target);
    if (event.key.code == sfKeyX) {
        my_window->tmp = 1;
        manage_score(my_window, my_target);
    } else if (event.key.code == sfKeyW) {
        my_window->tmp = 2;
        manage_score(my_window, my_target);
    }
}
