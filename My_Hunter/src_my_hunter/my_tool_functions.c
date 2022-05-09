/*
** EPITECH PROJECT, 2021
** my_tool_functions
** File description:
** Function to help my program
*/

#include "../include/my_hunter.h"

char my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return (count);
}

char *my_revstr(char *str)
{
    char my_string;
    char j = my_strlen(str) - 1;

    for (char i = 0; i < j; i++, j--) {
        my_string = str[i];
        str[i] = str[j];
        str[j] = my_string;
    }
    return (str);
}

char *my_int_to_str(int n)
{
    int tmp = 0;
    int i;
    char *my_string = malloc(sizeof(char) * my_int_len(n) + 1);

    if (n == 0)
        return ("0");
    if (my_string == NULL)
        return (0);
    my_string[my_int_len(n)] = '\0';
    for (i = 0; n > 9; i++) {
        tmp = n - (n % 10);
        my_string[i] = (n % 10) + '0';
        n = tmp / 10;
    }
    if (n <= 9)
        my_string[i] = n + '0';
    return (my_revstr(my_string));
    free(my_string);
}
