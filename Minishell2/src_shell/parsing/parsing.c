/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** parsing
*/

#include "shell.h"

int descriptor_resetting(redirection_t *entity)
{
    int count = 0;
    int pos = 0;
    char *reset = EMPTY;

    for (; entity->descriptor_b[pos] == '\t' ||
    entity->descriptor_b[pos] == ' '; pos++);
    for (count = pos; entity->descriptor_b[count] &&
    entity->descriptor_b[count] != '\t' && entity->descriptor_b[count] != ' ';
    count++);
    reset = malloc(((count - pos) + 1) * sizeof(char));
    if (!reset)
        return (FAILURE);
    for (count = pos, pos = 0; entity->descriptor_b[count] &&
    entity->descriptor_b[count] != '\t' && entity->descriptor_b[count] != ' ';
    reset[pos] = entity->descriptor_b[count], count++, pos++);
    reset[pos] = '\0';
    if (entity->descriptor_b)
        free(entity->descriptor_b);
    entity->descriptor_b = reset;
    return (SUCCESS);
}

int manage_entities_tool(shell_t *shell, redirection_t *entity)
{
    int result = SUCCESS;
    (around_pipe(entity->descriptor_a) == FAILURE) ? shell->output = 1,
    write_error(INSTRUCTION_ERROR), result = FAILURE : 0;
    ((get_redirection(entity->descriptor_b) ||
    get_redirection(entity->descriptor_a)) && result == SUCCESS) ?
    shell->output = 1, write_error(REDIRECTION_MISSING), result = FAILURE : 0;
    (get_pipe(entity->descriptor_b) && result == SUCCESS) ? shell->output = 1,
    write_error(REDIRECTION_AMBIGUOUS), result = FAILURE : 0;

    return (result);
}

int manage_entities(shell_t *shell, redirection_t *entity, char *cmd)
{
    int result = SUCCESS;
    entity->descriptor_a = parse_placement(cmd);
    entity->descriptor_b = parse_placement_s(&entity->mode, cmd);
    char **cmd_pipe = EMPTY;

    if (!entity->descriptor_a || !entity->descriptor_b)
        return (FAILURE);
    (manage_entities_tool(shell, entity) == FAILURE) ? result = FAILURE : 0;
    if (result == SUCCESS)
        (descriptor_resetting(entity) == FAILURE) ? result = FAILURE : 0;
    (get_pipe(entity->descriptor_a) && result == SUCCESS) ?
    cmd_pipe = my_str_to_word_array(entity->descriptor_a, "|"),
    (check_cmd_pipe(cmd_pipe) == FAILURE) ? (cmd_pipe) ? free_my_tab(cmd_pipe)
    : 0, write_error(INSTRUCTION_ERROR), shell->output = 1,
    result = FAILURE : 0,
    ((cmd_pipe) && result == SUCCESS) ? free_my_tab(cmd_pipe) : 0 : 0;
    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int start_pipe_parsing(shell_t *shell, int size, int occu, char *pipe_v)
{
    int result = SUCCESS;

    if (size > occu)
        pipe(shell->file);
    (occu == 0) ? (init_pipe(shell, pipe_v) == FAILURE) ?
    result = FAILURE : 0 : (size == occu) ?
    (init_pipe_s(shell, pipe_v) == FAILURE) ?
    result = FAILURE : 0 : (init_mul_pipe(shell, pipe_v) == FAILURE) ?
    result = FAILURE : 0;
    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
