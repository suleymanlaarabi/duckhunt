/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

void my_str_each_line(char *str, void (*func)(char *, char *), char *include)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0) {
            func(&str[i], include);
            continue;
        }
        if (str[i] == '\n')
            func(&str[i + 1], include);
    }
}
