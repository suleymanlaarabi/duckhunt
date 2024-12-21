/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

char *my_strcapitalize(char *str)
{
    if (str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;
    for (int i = 0; str[i] != '\0' && str[i + 1] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] >= 97 && str[i + 1] <= 122)
            str[i + 1] -= 32;
    }
    return str;
}
