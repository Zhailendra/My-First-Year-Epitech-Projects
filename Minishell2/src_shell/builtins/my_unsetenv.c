/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** my_unsetenv
*/

#include "shell.h"

char **generate_env(int main_var, shell_t *shell)
{
    char **my_own = malloc(sizeof(char *)
    * (my_tablen(shell->env) - main_var + 1));
    int b = 0;

    if (!shell->env || !my_own)
        return (EMPTY);
    for (int a = 0; shell->env[a]; a++)
        if (shell->env[a][0] != -1) {
            my_own[b] = my_strdup(shell->env[a]);
            b++;
        }
    my_own[b] = EMPTY;
    free_my_tab(shell->env);
    return (my_own);
}

int check_pos(shell_t *shell, char *unsetting)
{
    int check = -1;
    char *pos = my_strcat(unsetting, "=");

    if (!pos || !unsetting)
        return (check);
    check = get_env(pos, shell->env);
    free(pos);
    return (check);
}

int check_unsetenv_error(char **unsetting, shell_t *shell)
{
    if (!shell->env || !unsetting)
        return (-1);
    if (unsetting && unsetting[0] && !unsetting[1]) {
        write_error(UNSETENV_ERROR);
        shell->output = 1;
        return (-1);
    }
    return (SUCCESS);
}

int my_unsetenv(char **unsetting, shell_t *shell)
{
    int unset_var = 0;

    if (check_unsetenv_error(unsetting, shell) == -1)
        return (shell->output);
    for (int a = 1, b = 0; unsetting[a]; a++) {
        b = check_pos(shell, unsetting[a]);
        if (b != -1) {
            shell->env[b][0] = -1;
            unset_var += 1;
        }
    }
    shell->env = generate_env(unset_var, shell);
    return (shell->output);
}
