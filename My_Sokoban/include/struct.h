/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct {
    int *obj;
    int column;
    int lign;
    int count;
    int count_s;
    int move_to_x;
    int move_to_y;
    int end_of_the_map;
    int position_x;
    int position_y;
    int moves;
}map_t;

typedef struct {
    map_t *map_struct;
    char **tmp_tab;
    char *buffer;
    char *map;
    int fp;
}sokoban_t;

#endif
