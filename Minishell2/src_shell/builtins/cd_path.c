/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** cd_path
*/

#include "shell.h"

int get_place(char *pos)
{
    int result = 0;

    (!my_strncomp(pos, "OLDPWD=", 7)) ? result = 1 : 0;
    (!my_strncomp(pos, "PWD=", 4)) ? result = 1 : 0;
    return (result);
}

int manage_path(char *prev_path, char tmp[BUFFER_SIZE], shell_t *shell)
{
    char *create_path = my_strdup(getcwd(tmp, BUFFER_SIZE));
    shell->env = place_new_path(create_path, prev_path, shell);
    if (prev_path)
        free(prev_path);
    if (create_path)
        free(create_path);
    if (shell->env == EMPTY)
        return (FAILURE);
    return (SUCCESS);
}
