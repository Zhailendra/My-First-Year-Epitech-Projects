/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** setenv_tool
*/

#include "shell.h"

int replace_env(shell_t *shell)
{
    int length = 0;
    char **next = EMPTY;
    char **prev = shell->env;
    int tmp = 0;

    if (shell->env == EMPTY) {
        shell->env = malloc(sizeof(char *) * 2);
        shell->env[1] = EMPTY;
        return (SUCCESS);
    }
    while (prev[length] != EMPTY)
        length++;
    next = malloc(sizeof(char *) * (length + 2));
    if (next == EMPTY)
        return (-1);
    for (; prev[tmp] != EMPTY; next[tmp] = prev[tmp], tmp++);
    next[length + 1] = EMPTY;
    shell->env = next;
    free(prev);
    return (length);
}

int recup_env(char *setting, shell_t *shell)
{
    int count = 0;
    char *new_line = EMPTY;
    char *tmp = auto_alloc(setting);

    if (tmp == EMPTY || shell->env == EMPTY)
        return (-1);
    new_line = my_strcat(tmp, "=");
    free(tmp);
    while (shell->env[count]) {
        if (check_str_begin(new_line, shell->env[count])) {
            free(new_line);
            return (count);
        }
        count++;
    }
    free(new_line);
    return (-1);
}

char *get_my_env(char *setting, shell_t *shell)
{
    int length = 0;
    char *tmp = EMPTY;
    char *where = EMPTY;
    char *new = auto_alloc(setting);

    if (!new || !shell->env) {
        return (EMPTY);
    }
    where = my_strcat(new, "=");
    free(new);
    while (shell->env[length]) {
        (check_str_begin(where, shell->env[length])) ?
        tmp = auto_alloc(shell->env[length] + my_strlen(where)) : 0;
        length++;
    }
    free(where);
    return (tmp);
}
