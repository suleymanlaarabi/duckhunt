/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 33 && str[i] <= 126) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}
