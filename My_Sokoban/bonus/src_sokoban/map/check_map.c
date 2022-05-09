/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** check_map
*/

#include "sokoban.h"

struct stat check_map(sokoban_t *sokoban, struct stat my_stat)
{
    if (stat(sokoban->map, &my_stat) == -1) {
        write_error(FILE_FAILURE);
        exit(84);
    }
    return (my_stat);
}
