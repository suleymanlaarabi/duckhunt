/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** print_number_core
*/

#include "../../include/my.h"
#include "../../include/my_math.h"
#include "../../include/my_printf.h"
#include <stdarg.h>

static int print_first_part(double n)
{
    return my_put_nbr((long)n);
}

static int print_second_part(double n, int precision)
{
    unsigned long dec_part = get_dec(n);
    int dec_mag = decimal_magnitude(n);
    int total = 0;

    if (precision >= dec_mag) {
        dec_part = round_number(dec_part, precision - dec_mag);
    } else {
        dec_part = 0;
        dec_mag -= precision + 1;
    }
    if (precision != 0)
        total += my_putchar('.');
    if (dec_mag != 0 && precision != 0)
        total += my_printf("%0*d", dec_mag, 0);
    if (dec_part > 0 && !(dec_part >= lpow10(precision))) {
        total += my_printf("%d", dec_part);
    } else if (precision != 0) {
        total += my_printf("%0*d", precision, 0);
    }
    return total;
}

static int get_inc(double n, int precision)
{
    unsigned long dec_part = get_dec(n);
    int dec_mag = decimal_magnitude(n);

    if (precision >= dec_mag) {
        dec_part = round_number(dec_part, precision - dec_mag);
    } else {
        dec_part = 0;
        dec_mag -= precision + 1;
    }
    if (dec_part >= lpow10(precision))
        return 1;
    return 0;
}

int get_double_mag(double n)
{
    return (count_zero((long)n) + 1) + count_dec_zero(n);
}

int print_all_part(double n, int precision)
{
    int total = 0;

    total += print_first_part(n + get_inc(n, precision));
    total += print_second_part(n, precision);
    return total;
}
