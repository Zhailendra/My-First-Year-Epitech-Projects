/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** error_handle
*/

#include "shell.h"

int check_cd_error(char *cd, shell_t *shell)
{
    struct stat cd_stat;

    if (!cd)
        return (-1);
    if (stat(cd, &cd_stat) == -1) {
        print_error(cd);
        return (-1);
    }
    if (!access(cd, X_OK) && !S_ISDIR(cd_stat.st_mode)) {
        my_printf("%s", cd);
        write_error(CD_ERROR_ACCESS);
        shell->output = 1;
        return (-1);
    } else if (!S_ISDIR(cd_stat.st_mode)) {
        print_error(cd);
        shell->output = 1;
        return (-1);
    }
    return (1);
}

int my_alpha_checker(char c)
{
    if (my_str_isalpha(c)
    || my_str_isupper(c)
    || my_isdigit(c))
        return (1);
    return (SUCCESS);
}

int check_alphanum(char *string)
{
    for (; *string; string++) {
        if (!my_alpha_checker(*string)
        && *string != '(' && *string != ')') {
            my_printf("setenv: Variable name must contain alphanumeric");
            my_printf(" characters.\n");
            return (-1);
        }
    }
    return (SUCCESS);
}

int get_error_setenv(int occu, int occu_s)
{
    if (occu != 0 && occu_s != 0 && occu == occu_s) {
        my_printf("Badly placed ()'s.\n");
        return (-1);
    }
    if (occu != 0) {
        my_printf("Too many )'s.\n");
        return (-1);
    }
    if (occu_s != 0) {
        my_printf("Too many ('s.\n");
        return (-1);
    }
    return (SUCCESS);
}

int check_brackets(char **tab)
{
    int occu = 0;
    int occu_s = 0;

    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++) {
            tab[i][j] == '(' ? occu++ : 0;
            tab[i][j] == ')' ? occu_s++ : 0;
        }
    if (get_error_setenv(occu, occu_s) == -1)
        return (-1);
    return (SUCCESS);
}
