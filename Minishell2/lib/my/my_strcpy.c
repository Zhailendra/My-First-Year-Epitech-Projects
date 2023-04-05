/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int detail)
{
    int size = my_strlen(src);

    for (int a = 0; a < detail;) {
        dest[a] = src[a];
        a++;
        if (a == detail && size < detail)
            dest[a] = '\0';
    }
    return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
