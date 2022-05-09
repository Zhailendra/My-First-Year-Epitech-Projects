/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-shailendra.blondel
** File description:
** usage
*/

#include "sokoban.h"

void write_error(char *error)
{
    write(2, error, my_strlen(error));
}

void write_usage(void)
{
    my_printf("USAGE\n");
    my_printf("\t./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tmap file representing the warehouse map, containing '#' \
for walls,\n\tfor the players, 'X' for boxes and 'O' for storage \
locations.\n");
    my_printf("GAME\n");
    my_printf("\tPress Q to quit the game\n");
}

int manage_usage(int args, char **path)
{
    if (args == 2 && path[1][0] == '-' && path[1][1] == 'h') {
        write_usage();
        exit(SUCCESS);
    }
    if (args != 2) {
        write_error(WRONG_ARGS);
        return (-1);
    }
    return (SUCCESS);
}
