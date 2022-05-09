/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** get_obj_nb
*/

#include "sokoban.h"

int get_obj_nb(map_t *map_strcut, char **tab)
{
    for (int win = 0; win < map_strcut->end_of_the_map; win += 2) {
        map_strcut->count_s = map_strcut->obj[win];
        map_strcut->count = map_strcut->obj[win + 1];
        if (tab[map_strcut->count_s][map_strcut->count] != 'X')
            return (SUCCESS);
    }
    map_strcut->count = WIN;
    return (1);
}
