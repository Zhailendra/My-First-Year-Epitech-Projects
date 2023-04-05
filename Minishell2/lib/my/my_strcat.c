/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char const *dest, char const *src)
{
    char *result = malloc(my_strlen(dest)
    + my_strlen(src) + 1);
    int i = 0;

    if (dest)
        while ((*dest)) {
            result[i] = (char)(*dest);
            dest++;
            i++;
        }
    if (src)
        while ((*src)) {
            result[i] = (char)(*src);
            src++;
            i++;
        }
    result[i] = '\0';
    return (result);
}
