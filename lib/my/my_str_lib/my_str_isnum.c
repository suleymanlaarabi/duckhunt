/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int is_num(char c)
{
    if (c >= 47 && c <= 57)
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 47 && str[i] <= 57) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}
