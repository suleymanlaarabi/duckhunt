/*
** EPITECH PROJECT, 2024
** template
** File description:
** my_float_fact
*/

#include "../include/my_math.h"

long my_float_fact(int nb)
{
    long result = nb;

    if (nb == 0)
        return 1;
    if (nb < 0)
        return 0;
    if (nb > 15)
        return 0;
    for (int i = nb - 1; i >= 1; i--) {
        result *= i;
        if (result < nb)
            return 0;
    }
    return result;
}
