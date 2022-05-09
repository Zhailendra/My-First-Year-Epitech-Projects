/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** checker
*/

#include "sokoban.h"

int check_if_obj(int position_x, int position_y, map_t *map_struct)
{
    for (int check = 0; check < map_struct->end_of_the_map; check += 2)
        if (position_y == map_struct->obj[check] &&
        position_x == map_struct->obj[check + 1])
            return (SUCCESS);
    return (1);
}

int check_position(int position_x, int position_y, char **tab)
{
    if (tab[position_y][position_x] == 'O')
        return (IS_OBJ);
    if (tab[position_y][position_x] == 'x')
        return (IS_WALL);
    if (tab[position_y][position_x] == ' ')
        return (IS_FREE);
    if (tab[position_y][position_x] == 'X')
        return (IS_TARGET);
    return (SUCCESS);
}

int check_key(int key)
{
    if (key == 113)
        return (1);
    return (SUCCESS);
}

int check_tab(map_t *map, char **tab)
{
    if (tab == EMPTY)
        return (-1);
    get_end(map, tab);
    return (SUCCESS);
}
