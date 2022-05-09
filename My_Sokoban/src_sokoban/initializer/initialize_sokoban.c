/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** initialize_sokoban
*/

#include "sokoban.h"

map_t *initialize_map_struct(void)
{
    map_t *map_struct = malloc(sizeof(map_t));
    if (map_struct == EMPTY) {
        write_error(BAD_MALLOC);
        exit(FAILURE);
    }
    if ((map_struct->obj = malloc(sizeof(int) * 1000)) == EMPTY) {
        write_error(BAD_MALLOC);
        exit(FAILURE);
    }
    map_struct->column = 0;
    map_struct->lign = 0;
    map_struct->count = 0;
    map_struct->count_s = 0;
    map_struct->move_to_x = 0;
    map_struct->move_to_y = 0;
    map_struct->end_of_the_map = 0;
    map_struct->position_x = 0;
    map_struct->position_y = 0;
    map_struct->moves = 0;
    return (map_struct);
}

sokoban_t *initialize_sokoban(char *map_path)
{
    sokoban_t *sokoban = malloc(sizeof(sokoban_t));

    if (sokoban == EMPTY) {
        write_error(BAD_MALLOC);
        exit(FAILURE);
    }
    sokoban->map_struct = initialize_map_struct();
    sokoban->tmp_tab = EMPTY;
    sokoban->map = map_path;
    sokoban->fp = open(map_path, O_RDONLY);
    sokoban->buffer = EMPTY;
    return (sokoban);
}
