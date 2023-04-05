/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_strdup
*/

#include "my.h"

char *my_strndup(char const *src, int detail)
{
    char *dup = malloc(sizeof(char) * (detail + 1));

    if (dup == NULL)
        return (NULL);
    my_strncpy(dup, src, detail);
    dup[detail] = '\0';
    return (dup);
}

char *my_strdup(char const *src)
{
    int a = 0;
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[a] != '\0'; a++)
        str[a] = src[a];
    str[a] = '\0';
    return (str);
}
