/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** my_cd
*/

#include "shell.h"

int manage_cd_directive(char **cd, shell_t *shell)
{
    char tmp[BUFFER_SIZE];
    char *prev_path = my_strdup(getcwd(tmp, BUFFER_SIZE));

    if (prev_path == EMPTY)
        return (FAILURE);
    if (cd[0] && (cd[1] && !my_strcomp(cd[1], "-")))
        initial_dir(shell);
    else if ((cd[0] && (!cd[1] || !my_strcomp(cd[1], "~") ||
    (!my_strcomp(cd[1], "home")))))
        go_to_home(cd, shell);
    else
        (chdir(cd[1]) == -1) ? check_cd_error(cd[1], shell) : 0;
    if (manage_path(prev_path, tmp, shell) == FAILURE)
        return (FAILURE);
    return (1);
}

int my_cd(char **cd, shell_t *shell)
{
    if (my_tablen(cd) > 2) {
        write_error(CD_ARGS_ERROR);
        shell->output = 1;
        return (shell->output);
    }
    if (!cd || !cd[0])
        return (shell->output);
    if (manage_cd_directive(cd, shell) == FAILURE)
        return (FAILURE);
    return (shell->output);
}
