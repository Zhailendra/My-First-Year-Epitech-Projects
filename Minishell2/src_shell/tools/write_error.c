/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** write_error
*/

#include "shell.h"

void print_error(char *cd)
{
    my_printf("%s", cd);
    write_error(CD_DIRECTORY_ERROR);
}

void error_command(char **path, char **cmd, shell_t *shell)
{
    my_printf("%s", cmd[0]);
    write_error(COMMAND_NOT_FOUND);
    shell->output = 1;
    free_my_tab(path);
}

void write_error(char *error)
{
    write(2, error, my_strlen(error));
}
