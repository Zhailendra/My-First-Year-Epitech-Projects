/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** redirections
*/

#include "shell.h"

void init_redirection_in_s(shell_t *shell, redirection_t *entity)
{
    char *prev = EMPTY;
    int result = SUCCESS;
    (!my_strlen(entity->descriptor_b)) ? result = FAILURE,
    write_error(REDIRECTION_MISSING), shell->output = 1 : my_printf("? ");
    if (result == SUCCESS) {
        (result == SUCCESS) ? prev = parse_text(entity, prev) : 0;
        launch_double_rdl(shell, entity, prev);
        if (prev)
            free(prev);
    }
}

void init_redirection_in(shell_t *shell, redirection_t *entity)
{
    int result = SUCCESS;
    (!my_strlen(entity->descriptor_b)) ? result = FAILURE,
    write_error(REDIRECTION_MISSING), shell->output = 1 : 0;
    ((result == SUCCESS) && (shell->tmp_file = open(entity->descriptor_b,
    O_RDONLY)) == -1) ? result = FAILURE,
    my_printf("%s: No such file or directory.\n", entity->descriptor_b),
    shell->output = 1 : 0;
    ((result == SUCCESS) && (get_pipe(entity->descriptor_a))) ?
    result = FAILURE, write_error(REDIRECTION_AMBIGUOUS), shell->output = 1
    : 0;
    ((result == SUCCESS) && (entity->mode == 10)) ? launch(shell, entity) : 0;
    (shell->tmp_file != -1) ? close(shell->tmp_file) : 0;
}
