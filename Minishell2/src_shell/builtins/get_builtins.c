/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** get_builtins
*/

#include "shell.h"

int get_builtins(char **commands)
{
    int which_command = 0;
    char *my_builtins[] = {"cd", "env", "setenv",
    "unsetenv", "exit", EMPTY};

    if (!commands || !commands[0])
        return (which_command);
    for (; my_builtins[which_command]; which_command++)
        if (!my_strcomp(my_builtins[which_command], commands[0]))
            return (which_command);
    return (which_command);
}
