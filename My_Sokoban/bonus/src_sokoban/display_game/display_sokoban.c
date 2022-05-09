/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** display_sokoban
*/

#include "sokoban.h"

void display_movements(map_t *map_struct, char **tab)
{
    if (check_position(map_struct->position_x + map_struct->move_to_x,
    map_struct->position_y + map_struct->move_to_y, tab) > 0) {
        if (check_if_obj(map_struct->position_x,
        map_struct->position_y, map_struct) == SUCCESS)
            tab[map_struct->position_y][map_struct->position_x] = 'O';
        else
            tab[map_struct->position_y][map_struct->position_x] = ' ';
        map_struct->position_x += map_struct->move_to_x;
        map_struct->position_y += map_struct->move_to_y;
        tab[map_struct->position_y][map_struct->position_x] = 'P';
    }
}

void display_game(map_t *map_struct, char **tab, int coordinate_x,
int coordinate_y)
{
    for (; map_struct->count_s < map_struct->column;
    map_struct->count_s++) {
        coordinate_y = LINES / 2 + map_struct->count_s;
        coordinate_x = COLS / 2;
        if (COLS < map_struct->lign ||
        LINES < map_struct->column + 1)
            mvprintw(LINES / 2, coordinate_x - 13,
            "Increase the terminal size");
        else
            mvprintw(coordinate_y - map_struct->column / 2,
            coordinate_x - map_struct->lign / 2,
            tab[map_struct->count_s]);
    }
    mvprintw(coordinate_y - 3, coordinate_x - 14,
    "Number of movements you did: %d",
    map_struct->moves);
}

int display_sokoban(sokoban_t *sokoban, char **tab, int display)
{
    int coordinate_x = 0;
    int coordinate_y = 0;
    int key = 0;

    display_game(sokoban->map_struct, tab, coordinate_x, coordinate_y);
    refresh();
    key = getch();
    tab = check_if_reset(sokoban, tab, key);
    sokoban->map_struct->move_to_x = 0;
    sokoban->map_struct->move_to_y = 0;
    check_movements(sokoban->map_struct, tab, key);
    if (check_key(key) == 1)
        return (1);
    display = get_obj_nb(sokoban->map_struct, tab);
    return (display);
}
