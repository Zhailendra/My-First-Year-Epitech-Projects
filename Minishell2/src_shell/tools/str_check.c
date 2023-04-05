/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** str_check
*/

#include "shell.h"

int check_str_begin(char *new, char *old)
{
    while (*new) {
        if (*old != *new)
            return (SUCCESS);
        new++;
        old++;
    }
    return (1);
}

void *auto_alloc(char *any)
{
    int size = 0;
    char *allocated = EMPTY;

    if (any != EMPTY)
        allocated = malloc(sizeof(char) * (my_strlen(any) + 1));
    if (allocated == EMPTY)
        return (EMPTY);
    while (any[size]) {
        allocated[size] = any[size];
        size++;
    }
    allocated[size] = '\0';
    return ((char *)allocated);
}
