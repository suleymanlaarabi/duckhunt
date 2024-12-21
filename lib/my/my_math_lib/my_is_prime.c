/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_is_prime(int nb)
{
    int is_prime = 1;

    if (nb < 2)
        return 0;
    for (int i = 2; i <= nb - 1; i++) {
        if (nb % i == 0) {
            is_prime = 0;
        }
    }
    return is_prime;
}
