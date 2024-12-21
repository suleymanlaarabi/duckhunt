/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

unsigned long long my_compute_power_rec(
    unsigned long long nb, unsigned long long p)
{
    if (nb > 2147483647)
        return 0;
    if (p == 1)
        return nb;
    if (p == 0)
        return 1;
    return nb * my_compute_power_rec(nb, p - 1);
}
