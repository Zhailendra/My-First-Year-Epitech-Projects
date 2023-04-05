/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-shailendra.blondel
** File description:
** my_get_next_line is a function that get the next line of
** a file in input
*/

#include "../my_get_nl.h"

int end(char *buff);

char *my_realloc(int util, char *prev_line, char *size)
{
    int a = 0;
    char *new_b = NULL;

    if (util) {
        new_b = my_strcat(prev_line, size);
        free(prev_line);
        return (new_b);
    }
    for (; prev_line[a + 1] != '\0' && prev_line[a + 1] != '\n';
    a++);
    if (prev_line[a + 1] == '\0') {
        free(prev_line);
        return (NULL);
    }
    new_b = my_strdup(prev_line + a + 2);
    free(prev_line);
    return (new_b);
}

char *get_next(int *tmp, int fp, char *buff)
{
    char size[128 + 1];

    if (size == NULL || buff == NULL)
        return (NULL);
    for (; !end(buff) && *tmp != 0;) {
        *tmp = read(fp, size, 128);
        if (*tmp == -1)
            return (NULL);
        size[*tmp] = '\0';
        buff = my_realloc(1, buff, size);
    }
    return (buff);
}

int end(char *buff)
{
    for (int occu = 0; buff[occu] != '\0'; occu++)
        if (buff[occu] == '\n')
            return (1);
    return (0);
}

char *my_lines(char *buff)
{
    int a = 0;
    char *line = NULL;

    if (buff && buff[0] == '\n')
        return (my_strdup("\n"));
    for (; buff[a] != '\0' && buff[a] != '\n'; a++);
    line = my_strndup(buff, a);
    return (line);
}

char *my_get_next_line(int fp)
{
    int tmp = 1;
    static char *buff = NULL;
    char *next = NULL;

    if (buff == NULL)
        buff = my_strdup("\0");
    if (fp == -1)
        return (NULL);
    buff = get_next(&tmp, fp, buff);
    if (buff == NULL || (buff[0] == '\0' &&
    tmp == 0)) {
        free(buff);
        return (NULL);
    }
    next = my_lines(buff);
    buff = my_realloc(0, buff, buff);
    return (next);
}
