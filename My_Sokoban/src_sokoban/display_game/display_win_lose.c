/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** display_win_lost
*/

#include "sokoban.h"

void display_win_information(sokoban_t *sokoban, int coordinate_x,
int coordinate_y)
{
    mvprintw(coordinate_y - 3, coordinate_x - 10,
    "CONGRATULATION");
    mvprintw(coordinate_y - 1, coordinate_x - 17,
    "Press SPACE to reset the game");
    mvprintw(coordinate_y - 5, coordinate_x - 13,
    "You did: %d movements!", sokoban->map_struct->moves);
}

void conditions_then_display(sokoban_t *sokoban)
{
    free_all(sokoban, sokoban->tmp_tab);
    sokoban->map_struct->count = 0;
    sokoban->map_struct->count_s = 0;
    sokoban->tmp_tab = get_tab(sokoban->tmp_tab, sokoban,
    sokoban->map_struct, 0);
    sokoban->map_struct->moves = 0;
}

void *display_win_terminal(sokoban_t *sokoban, int coordinate_x,
int coordinate_y, int key)
{
    for (; key != 113;) {
        coordinate_x = COLS / 2;
        coordinate_y = LINES / 2;
        if (LINES < 7 || COLS < 22)
            mvprintw(LINES / 2, coordinate_x - 10,
            "Increase the terminal size");
        else if (key == 32) {
            conditions_then_display(sokoban);
            return (start_sokoban(sokoban, sokoban->tmp_tab));
        } else {
            display_win_information(sokoban, coordinate_x,
            coordinate_y);
        }
        key = getch();
        clear();
        refresh();
    }
    return (sokoban->tmp_tab);
}

void display_if_win(sokoban_t *sokoban, char **tab)
{
    int coordinate_x = 0;
    int coordinate_y = 0;
    int key = 0;
    sokoban->tmp_tab = tab;

    if (sokoban->map_struct->count == WIN) {
        clear();
        tab = display_win_terminal(sokoban, coordinate_x,
        coordinate_y, key);
    }
}
