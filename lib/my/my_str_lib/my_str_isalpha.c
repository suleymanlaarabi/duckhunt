/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

short is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 97 && str[i] <= 122) ||
            (str[i] >= 65 && str[i] <= 90)) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}
