/*
** EPITECH PROJECT, 2024
** template
** File description:
** my_float_power
*/

#include "../include/my_math.h"

double my_float_power(double n, double p)
{
    double old = n;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    if (p > 0)
        p--;
    for (; p > 0; p--)
        n *= old;
    return n;
}
