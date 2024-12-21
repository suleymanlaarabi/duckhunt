/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb == 1)
        return 1;
    for (; i <= 2147483647; i++) {
        if (i >= nb)
            return 0;
        if (i * i == nb)
            break;
    }
    return i;
}
