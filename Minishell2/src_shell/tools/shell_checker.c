/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** shell_checker
*/

#include "shell.h"

char *get_more_place_for_text(char *tmp, char *prev)
{
    int size = 0;
    char *alloc = malloc((my_strlen(prev) + my_strlen(tmp) + 2)
    * sizeof(char));

    if (alloc == EMPTY)
        return (EMPTY);
    for (int length = 0; prev[length]; length++)
        alloc[size++] = prev[length];
    for (int length = 0; tmp[length]; length++)
        alloc[size++] = tmp[length];
    alloc[size] = '\n';
    alloc[size + 1] = '\0';
    if (prev)
        free(prev);
    return (alloc);
}

int around_pipe(char *pipe)
{
    int result = FAILURE;

    for (int tmp = 0; pipe[tmp] != '\0'; tmp++)
        (pipe[tmp] != '\t' && pipe[tmp] != ' ') ? result = SUCCESS : 0;
    return (result);
}

char *get_place_for_text(char *tmp)
{
    int size = 0;
    char *alloc = malloc((my_strlen(tmp) + 2) * sizeof(char));

    if (alloc == EMPTY)
        return (EMPTY);
    for (; tmp[size] != '\0'; size++)
        alloc[size] = tmp[size];
    alloc[size] = '\n';
    alloc[size + 1] = '\0';
    return (alloc);
}

int check_cmd_pipe(char **cmd_pipe)
{
    int result = SUCCESS;
    (my_tablen(cmd_pipe) == 1) ? result = FAILURE : 0;

    if (result == SUCCESS)
        for (int count = 0; cmd_pipe[count]; count++)
            (around_pipe(cmd_pipe[count]) == FAILURE) ? result = FAILURE : 0;
    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
