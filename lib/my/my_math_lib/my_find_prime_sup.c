/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 1)
        return 2;
    for (; nb <= 2147483647; nb++)
        if (my_is_prime(nb) == 1)
            return nb;
}
