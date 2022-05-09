/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** get_end
*/

#include "sokoban.h"

int tool_get_end(map_t *map_struct, char **tab, int result)
{
    for (; map_struct->count < map_struct->lign; map_struct->count++) {
        if (tab[map_struct->count_s][map_struct->count] == 'O') {
            map_struct->obj[result] = map_struct->count_s;
            map_struct->obj[result + 1] = map_struct->count;
            result += 2;
        }
    }
    return (result);
}

void get_end(map_t *map_struct, char **tab)
{
    int result = 0;
    map_struct->count = 0;
    map_struct->count_s = 0;

    for (; map_struct->count_s < map_struct->column; map_struct->count_s++) {
        result = tool_get_end(map_struct, tab, result);
        map_struct->count = 0;
    }
    map_struct->end_of_the_map = result;
}
