/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** get_tab
*/

#include "sokoban.h"

void *map_malloc(map_t *map_struct, char **tab)
{
    if ((tab[map_struct->count_s] = malloc
    ((map_struct->lign + 1) * sizeof(char))) == EMPTY)
        return (EMPTY);
    return (tab);
}

int tool_tab_check(sokoban_t *sokoban, map_t *map_struct, char **tab,
int n)
{
    if (sokoban->buffer[n] == 'P') {
        map_struct->position_y = map_struct->count_s;
        map_struct->position_x = map_struct->count;
    }
    if (sokoban->buffer[n] == '\n') {
        tab[map_struct->count_s][map_struct->count + 1] = '\0';
        map_struct->count = map_struct->lign;
    } else
        n++;
    return (n);
}

char **position_tab_check(sokoban_t *sokoban, map_t *map_struct, char **tab,
int n)
{
    for (; map_struct->count_s < map_struct->column; map_struct->count_s++) {
        if (map_malloc(sokoban->map_struct, tab) == EMPTY)
            return (EMPTY);
        for (;map_struct->count < map_struct->lign; map_struct->count++) {
        tab[map_struct->count_s][map_struct->count] = sokoban->buffer[n];
        n = tool_tab_check(sokoban, sokoban->map_struct, tab, n);
        }
        n++;
        map_struct->count = 0;
    }
    return (tab);
}

char **get_tab(char **tab, sokoban_t *sokoban, map_t *map_struct, int n)
{
    tab = malloc((map_struct->column + 1) * sizeof(char *));

    if (tab == EMPTY)
        return (EMPTY);
    tab = position_tab_check(sokoban, sokoban->map_struct, tab, n);
    return (tab);
}
