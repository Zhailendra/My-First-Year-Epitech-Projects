/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** check_movements
*/

#include "sokoban.h"

void check_movements(map_t *map, char **tab, int key)
{
    switch (key) {
        case KEY_UP:
            map->move_to_y = -1;
            map->moves++;
            break;
        case KEY_DOWN:
            map->move_to_y = 1;
            map->moves++;
            break;
        case KEY_LEFT:
            map->move_to_x = -1;
            map->moves++;
            break;
        case KEY_RIGHT:
            map->move_to_x = 1;
            map->moves++;
            break;
    }
    get_movements(map, tab);
}
