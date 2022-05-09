/*
** EPITECH PROJECT, 2022
** PSU-2
** File description:
** main
*/

#include "sokoban.h"

void free_all(sokoban_t *sokoban, char **tab)
{
    for (sokoban->map_struct->count_s = 0; sokoban->map_struct->count_s <
    sokoban->map_struct->column; sokoban->map_struct->count_s++)
        free(tab[sokoban->map_struct->count_s]);
    free(tab);
}

void *start_sokoban(sokoban_t *sokoban, char **tab)
{
    initscr();
    curs_set(0);
    raw();
    keypad(stdscr, 1);
    noecho();

    for (int display = 0; display == 0; display =
    display_sokoban(sokoban, tab, display)) {
        clear();
        sokoban->map_struct->count_s = 0;
    }
    display_if_win(sokoban, tab);
    endwin();
    return (SUCCESS);
}

int main_sokoban(char *map_path)
{
    sokoban_t *sokoban = initialize_sokoban(map_path);
    char **tab = EMPTY;

    if (get_map(sokoban) == -1) {
        write_error(BAD_MAP);
        return (-1);
    }
    get_lign(sokoban, sokoban->map_struct);
    get_column(sokoban, sokoban->map_struct);
    sokoban->map_struct->count = 0;
    sokoban->map_struct->count_s = 0;
    tab = get_tab(tab, sokoban, sokoban->map_struct, 0);
    if (check_tab(sokoban->map_struct, tab) == -1)
        return (-1);
    start_sokoban(sokoban, tab);
    close(sokoban->fp);
    free_all(sokoban, tab);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (manage_usage(ac, av) == -1)
        return (FAILURE);
    if (main_sokoban(av[1]) == -1)
        return (FAILURE);
    return (SUCCESS);
}
