/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** round_number
*/

#include "../include/my_math.h"
#include "../include/my.h"

// return the magnitude of the number after coma
int count_dec_zero(double n)
{
    int to_remove = n;
    int result = 0;

    while ((n - to_remove) > 0.000009 && (n - to_remove) < 0.999999) {
        n *= 10;
        to_remove = n;
        result++;
    }
    if (result >= 5)
        result++;
    return result;
}

// return decimal magnitude
// ex: 0.0321
// ->  2
int decimal_magnitude(double n)
{
    return count_dec_zero(n) - (count_zero(get_dec(n)) + 1);
}
