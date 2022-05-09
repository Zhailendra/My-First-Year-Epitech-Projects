/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_strcmp
*/

#include "my.h"

int my_strncomp(char *string1, char *string2, int occu)
{
    for (int a = 0; a < occu && (string1[a] &&
    string2[a]); a++) {
        if (string1[a] < string2[a])
            return (-1);
        if (string1[a] > string2[a])
            return (1);
    }
    return (0);
}

int my_strcomp(char *string1, char *string2)
{
    if (!string1 || !string2)
        return (84);
    for (; (*string1 == *string2) && *string1 != '\0'
    && *string2 != '\0'; string1++, string2++);
    return (*string1 - *string2);
}
