/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** round_number
*/

#include "../include/my.h"
#include "../include/my_math.h"

// ex: num: 14159, round: 3
// -> 142
//
// 11   578 -> 1000 / 2
unsigned long round_number(unsigned long num, unsigned long round)
{
    unsigned long magnitude = count_zero(num) + 1;
    unsigned long right_part = 0;
    unsigned long left_part = 0;

    if (round > magnitude)
        return num * lpow10(round - magnitude);
    right_part = num % lpow10(magnitude - round);
    left_part = num / lpow10(magnitude - round);
    if (num == 0)
        return num;
    if (right_part > lpow10(count_zero(right_part) + 1) / 2)
        return left_part + 1;
    return left_part;
}

unsigned long get_dec(double n)
{
    int decimal_mag = count_dec_zero(n);

    return (float)((n - (long)n) * lpow10(decimal_mag));
}

double round_double(double n, int round)
{
    double rigt_part = round_number(get_dec(n), round);
    double left_part = (long)n;

    return left_part + rigt_part / lpow10(count_zero(rigt_part) + 1);
}
