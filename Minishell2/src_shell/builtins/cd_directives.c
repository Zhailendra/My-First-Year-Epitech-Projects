/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** cd_directive
*/

#include "shell.h"

void initial_dir(shell_t *shell)
{
    int pos = get_env("OLDPWD=", shell->env);

    if (pos != -1)
        shell->output = chdir(shell->env[pos] + 7);
    else {
        shell->output = 1;
        write_error(CD_DIRECTORY_ERROR);
    }
}

void go_to_home(char **cd, shell_t *shell)
{
    int pos = get_env("HOME=", shell->env);

    if (pos != -1) {
        shell->output = chdir(shell->env[pos] + 5);
        (!my_strcomp(cd[1], "home")) ? write(1, "~\n", 2) : 0;
    } else if (!my_strcomp(cd[1], "~") && pos == -1) {
        shell->output = 1;
        write_error("No $home variable set.\n");
    } else {
        shell->output = 1;
        (cd[1]) ? write_error("home: No such file or directory.\n") :
        write_error("cd: No such file or directory.\n");
    }
}

void cat_to_env(int b, char *prev_path, char **new_env, char *path)
{
    path = my_strcat("OLDPWD=", prev_path);
    new_env[b + 1] = my_strdup(path);
    new_env[b + 2] = EMPTY;
    if (path)
        free(path);
}

char **place_new_path(char *create_path, char *prev_path, shell_t *shell)
{
    int b = 0;
    char *path = EMPTY;
    char **new_env = EMPTY;
    int tmp = 0;

    if (get_env("OLDPWD=", shell->env) == -1 ||
    get_env("PWD=", shell->env) == -1)
        tmp++;
    new_env = malloc((my_tablen(shell->env) + tmp + 1) * sizeof(char *));
    if (new_env == EMPTY)
        return (EMPTY);
    for (int a = -1; shell->env[++a]; (!get_place(shell->env[a]))
    ? new_env[b++] = my_strdup(shell->env[a]) : 0);
    path = my_strcat("PWD=", create_path);
    new_env[b] = my_strdup(path);
    if (path)
        free(path);
    cat_to_env(b, prev_path, new_env, path);
    free_my_tab(shell->env);
    return (new_env);
}
