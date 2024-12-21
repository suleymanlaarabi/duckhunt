/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_compute_factorial_it(int nb)
{
    int result = nb;

    if (nb == 0)
        return 1;
    if (nb < 0)
        return 0;
    if (nb > 12)
        return 0;
    for (int i = nb - 1; i >= 1; i--) {
        result *= i;
        if (result < nb)
            return 0;
    }
    return result;
}
