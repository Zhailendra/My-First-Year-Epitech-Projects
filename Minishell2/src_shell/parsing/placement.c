/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** placement
*/

#include "shell.h"

char *parse_text(redirection_t *entity, char *prev)
{
    char *line = EMPTY;

    for (; 1;) {
        line = my_get_next_line(0);
        if (line == EMPTY)
            return (EMPTY);
        if (!my_strcomp(line, entity->descriptor_b))
            break;
        (prev == EMPTY) ? prev = get_place_for_text(line) :
        (prev = get_more_place_for_text(line, prev));
        if (prev == EMPTY)
            return (EMPTY);
        my_printf("? ");
        if (line)
            free(line);
    }
    (line) ? free(line) : 0;
    return (prev);
}

char *parse_placement_s(int *mode, char *cmd)
{
    int count = 0;
    char *place = EMPTY;
    int pos = 0;

    if (!cmd)
        return (EMPTY);
    for (; cmd[count] != '<' && cmd[count] != '>'; count++);
    (cmd[count + 1] == '>' && cmd[count] == '>') ? *mode = 2 :
    ((cmd[count + 1] != '>' && cmd[count] == '>') ? *mode = 1 :
    ((cmd[count + 1] == '<' && cmd[count] == '<') ? *mode = 3 :
    (*mode = 10)));
    if ((cmd[count + 1] == '<' && cmd[count] == '<') ||
    (cmd[count + 1] == '>' && cmd[count] == '>'))
        count++;
    place = malloc((my_strlen(cmd) + 1 - count) * sizeof(char));
    if (!place)
        return (EMPTY);
    for (; cmd[++count]; place[pos++] = cmd[count]);
    place[pos] = '\0';
    return (place);
}

void launch_double_rdl(shell_t *shell, redirection_t *entity, char *prev)
{
    int status = 0;
    int pipe_v[2];
    pid_t my_pid = fork();
    pipe(pipe_v);
    write(pipe_v[1], prev, my_strlen(prev));

    if (my_pid == -1) {
        shell->output = 1;
        return (write_error(PROCESS_ERROR));
    }
    (my_pid == 0) ? dup2(pipe_v[0], 0), close(pipe_v[1]),
    handle_commands(entity->descriptor_a, shell), exit(1) :
    close(pipe_v[0]), close(pipe_v[1]), wait(&status);
}

void launch(shell_t *shell, redirection_t *entity)
{
    int status = 0;
    pid_t my_pid = fork();

    if (my_pid == -1) {
        shell->output = 1;
        return (write_error(PROCESS_ERROR));
    }
    (my_pid == 0) ? dup2(shell->tmp_file, 0),
    handle_commands(entity->descriptor_a, shell), exit(1) : wait(&status);
}

char *parse_placement(char *cmd)
{
    int count = 0;
    char *place = EMPTY;

    if (!cmd)
        return (EMPTY);
    for (; cmd[count] != '>' && cmd[count] != '<'; count++);
    for (; cmd[0] == '\t' || cmd[0] == ' '; cmd++);
    place = malloc((count + 1) * sizeof(char));
    if (!place)
        return (EMPTY);
    for (count = 0; cmd[count] != '>' && cmd[count] != '<';
    place[count] = cmd[count], count++);
    place[count] = '\0';
    return (place);
}
