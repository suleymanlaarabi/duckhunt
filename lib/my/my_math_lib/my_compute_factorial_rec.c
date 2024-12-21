/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_compute_factorial_rec(int nb)
{
    if (nb < 0)
        return 0;
    if (nb > 12)
        return 0;
    if (nb <= 1)
        return 1;
    return nb * my_compute_factorial_rec(nb - 1);
}
