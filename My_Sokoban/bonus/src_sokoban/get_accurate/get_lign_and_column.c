/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** get_lign_and_column
*/

#include "sokoban.h"

void get_column(sokoban_t *sokoban, map_t *map_struct)
{
    for (map_struct->count = 0; sokoban->buffer[map_struct->count];
    map_struct->count++)
        if (sokoban->buffer[map_struct->count] == '\n')
            map_struct->column++;
}

void get_lign(sokoban_t *sokoban, map_t *map_struct)
{
    for (int result = 0; sokoban->buffer[map_struct->count];
    map_struct->count++) {
        if (sokoban->buffer[map_struct->count] == '\n' &&
        result > map_struct->lign) {
            map_struct->lign = result - 1;
            result = 0;
        }
        result++;
    }
}
