/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** get_movements
*/

#include "sokoban.h"

void get_movements(map_t *map_struct, char **tab)
{
    if (check_position(map_struct->position_x + map_struct->move_to_x,
    map_struct->position_y + map_struct->move_to_y, tab) < 0 &&
    check_position(map_struct->position_x + map_struct->move_to_x * 2,
    map_struct->position_y + map_struct->move_to_y * 2, tab) > 0) {
        if (check_if_obj(map_struct->position_x,
        map_struct->position_y, map_struct) == SUCCESS)
            tab[map_struct->position_y][map_struct->position_x] = 'O';
        else
            tab[map_struct->position_y][map_struct->position_x] = ' ';
        map_struct->position_x += map_struct->move_to_x;
        map_struct->position_y += map_struct->move_to_y;
        tab[map_struct->position_y][map_struct->position_x] = 'P';
        tab[map_struct->position_y + map_struct->move_to_y]
        [map_struct->position_x + map_struct->move_to_x] = 'X';
    }
    display_movements(map_struct, tab);
}
