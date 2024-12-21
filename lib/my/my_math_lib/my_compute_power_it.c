/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

int my_compute_power_it(int n, int p)
{
    int old = n;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    if (p > 0)
        p--;
    for (; p > 0; p--)
        n *= old;
    if (n > 2147483647) {
        return 0;
    }
    return n;
}

unsigned long my_compute_lpow(unsigned long n, unsigned long p)
{
    long old = n;

    if (p == 0)
        return 1;
    if (p > 0)
        p--;
    for (; p > 0; p--)
        n *= old;
    if (n > 2147483647) {
        return 0;
    }
    return n;
}

unsigned long lpow10(unsigned long n)
{
    return my_compute_lpow(10, n);
}
