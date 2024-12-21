/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);

    for (int i = 0; i <= len1; i++) {
        if (s1[i] == s2[i])
            continue;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
