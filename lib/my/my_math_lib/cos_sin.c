/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my_math.h"
#include "../include/my.h"

double my_sin(double x)
{
    double result;
    short is_neg = 1;

    x = my_float_modulo(x, 2 * MY_PI);
    result = x;
    for (int i = 3; i <= 15; i += 2) {
        if (is_neg == 1) {
            result -= my_float_power(x, i) / my_float_fact(i);
        } else
            result += my_float_power(x, i) / my_float_fact(i);
        is_neg = !is_neg;
    }
    return result;
}

double my_cos(double x)
{
    UNUSED(x);
    return 0.0;
}
