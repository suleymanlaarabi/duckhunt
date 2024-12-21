/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my_math.h"

double my_float_modulo(double x, double y)
{
    long result = x / y;
    double rest = x - (result * y);

    return rest;
}
