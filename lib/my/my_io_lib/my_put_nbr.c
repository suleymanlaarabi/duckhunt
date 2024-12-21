/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stdlib.h>

unsigned long count_zero(unsigned long n)
{
    unsigned long long result = 0;

    while (n > 0) {
        n /= 10;
        result++;
    }
    return result - 1;
}

int final(unsigned long long n)
{
    unsigned long long factor = my_compute_power_rec(10, count_zero(n));
    unsigned long long counter = count_zero(n) + 1;
    int len = 0;

    while (counter > 0) {
        my_putchar((n / factor) + 48);
        n = n % factor;
        factor = factor / 10;
        counter--;
        len++;
    }
    return len;
}

int my_put_nbr(long n)
{
    int is_neg = 0;

    if (n == -2147483648) {
        my_putstr("-2147483648");
        return 11;
    }
    if (n < 0) {
        is_neg = my_putchar('-');
        n = n * -1;
    }
    if (n == 0) {
        my_putchar('0');
        return 1;
    }
    return final(n) + is_neg;
}
