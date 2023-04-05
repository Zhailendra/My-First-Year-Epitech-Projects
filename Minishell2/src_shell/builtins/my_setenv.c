/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** my_setenv
*/

#include "shell.h"

int get_env(char *set, char **env)
{
    for (int a = 0; env[a]; a++) {
        if (!my_strncomp(env[a], set, my_strlen(set)))
            return (a);
    }
    return (-1);
}

char **modif_env(shell_t *shell, char **setting)
{
    int where = 0;
    char *old = my_strcat(setting[1], "=");
    char *new_line = setting[2] ? my_strcat(old, setting[2]) : old;
    char *tmp = get_my_env(setting[1], shell);

    (setting[2]) ? free(old) : 0;
    (tmp) ? where = recup_env(setting[1], shell), free(shell->env[where])
    : (where = replace_env(shell));
    shell->env[where] = new_line;
    free(tmp);
    return (shell->env);
}

int check_setenv_error(char **setting, shell_t *shell)
{
    if (my_tablen(setting) > 3) {
        write_error(SETENV_ARGS_ERROR);
        shell->output = 1;
        return (-1);
    }
    if (!my_str_isalpha_setenv(setting[1][0]) &&
    !my_str_isupper(setting[1][0])) {
        write_error(SETENV_ARGS_ERROR_S);
        shell->output = 1;
        return (-1);
    }
    if (check_brackets(setting) == -1
    || check_alphanum(setting[1]) == -1) {
        shell->output = 1;
        return (-1);
    }
    return (SUCCESS);
}

int my_setenv(char **setting, shell_t *shell)
{
    if (!setting || !shell->env)
        return (shell->output);
    if (my_tablen(setting) == 1) {
        my_env(setting, shell);
        return (shell->output);
    }
    if (check_setenv_error(setting, shell) == -1)
        return (shell->output);
    shell->env = modif_env(shell, setting);
    return (shell->output);
}
