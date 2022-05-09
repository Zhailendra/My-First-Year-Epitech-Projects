/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** get_map
*/

#include "sokoban.h"

int tool_error_map(sokoban_t *sokoban)
{
    int obj = 0;
    int obj_s = 0;
    int player = 0;

    for (int i = 0; sokoban->buffer[i]; i++) {
        if (sokoban->buffer[i] == 'O')
            obj++;
        if (sokoban->buffer[i] == 'X')
            obj_s++;
        if (sokoban->buffer[i] == 'P')
            player++;
    }
    if (player == 0 || player > 1)
        return (-1);
    if (obj > obj_s)
        return (-1);
    return (SUCCESS);
}

int error_map(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->buffer[i]; i ++) {
        if (sokoban->buffer[i] != '#' && sokoban->buffer[i] !=
        'O' && sokoban->buffer[i] != 'X' && sokoban->buffer[i] !=
        '\n' && sokoban->buffer[i] != ' ' && sokoban->buffer[i] !=
        'P')
            return (-1);
    }
    return (SUCCESS);
}

void get_map_size(sokoban_t *sokoban, struct stat my_stat)
{
    sokoban->buffer = malloc(my_stat.st_size + 1);
    read(sokoban->fp, sokoban->buffer, my_stat.st_size);
    sokoban->buffer[my_stat.st_size] = '\0';
}

int get_map(sokoban_t *sokoban)
{
    struct stat my_stat;

    my_stat = check_map(sokoban, my_stat);
    get_map_size(sokoban, my_stat);
    if (error_map(sokoban) == -1)
        return (-1);
    if (tool_error_map(sokoban) == -1)
        return (-1);
    return (SUCCESS);
}
