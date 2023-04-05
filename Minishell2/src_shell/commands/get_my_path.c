/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** get_my_path
*/

#include "shell.h"

char *env_position(char *path, char **env)
{
    int tmp_var = 0;
    char *tmp = EMPTY;

    while (env[tmp_var] != EMPTY) {
        if (!my_strncomp(env[tmp_var], path, my_strlen(path)))
            break;
        tmp_var += 1;
    }
    if (!env[tmp_var])
        return (EMPTY);
    tmp = malloc((my_strlen(env[tmp_var]) + 1) * sizeof(char));
    tmp = my_strcpy(tmp, env[tmp_var]);
    while (*tmp != '=')
        tmp++;
    return (tmp + 1);
}

char *get_my_path(char *tmp, char *path)
{
    int j = 0;
    int count = 0;
    int tmp_v = 0;

    if ((tmp = malloc(my_strlen(path) * sizeof(char))) == EMPTY) {
        write_error(BAD_MALLOC);
        return (EMPTY);
    }
    for (int i = 0; path[i]; i++)
        path[i] == '/' ? count++ : 0;
    for (; path[j] && count > 0; j++)
        path[j] == '/' ? count-- : 0;
    for (; path[j]; j++)
        tmp[tmp_v++] = path[j];
    tmp[tmp_v] = '\0';
    return (tmp);
}
