/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** get_exe
*/

#include "shell.h"

char *get_command_path(char *cmd, char *current)
{
    char *tmp = EMPTY;
    int size = my_strlen(current);
    char *str = EMPTY;
    tmp = malloc(sizeof(char) * (size + my_strlen(cmd) + 2));

    if (tmp == EMPTY) {
        write_error(BAD_MALLOC);
        return (EMPTY);
    }
    tmp = my_strcpy(tmp, current);
    tmp[size - 1] != '/' ? tmp[size] = '/', tmp[size + 1] = '\0' : 0;
    str = my_strcat(tmp, cmd);
    free(tmp);
    return (str);
}
