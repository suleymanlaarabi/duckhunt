/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

int my_putline(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
    return 0;
}

int print_count(int n, char c)
{
    int result = 0;

    for (; n > 0; n--) {
        my_putchar(c);
        result++;
    }
    return result;
}
