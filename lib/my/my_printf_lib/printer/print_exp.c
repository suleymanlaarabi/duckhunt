/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** print_float
*/

#include "../../include/my.h"
#include "../../include/my_math.h"
#include "../../include/my_printf.h"
#include <stdarg.h>

exp_data_t get_exp(double n)
{
    exp_data_t info = {0, 0};

    if (n == 0.0) {
        info.exp = 0;
        info.value = 0;
        return info;
    }
    if ((long) MY_ABS(n) > 0.9999) {
        info.exp = count_zero(MY_ABS(n));
        info.value = n / lpow10(count_zero(MY_ABS(n)));
    } else {
        info.exp = -(decimal_magnitude(MY_ABS(n)) + 1);
        info.value = n * lpow10(decimal_magnitude(MY_ABS(n)) + 1);
    }
    return info;
}

void print_exp_core(exp_data_t info, ca_params_t params)
{
    *params.total += my_printf("%.6f", info.value);
    if (info.value == 0.0) {
        *params.total += my_putstr("e+00");
        return;
    }
    if (info.exp >= 0) {
        *params.total += my_printf("e+%02d", info.exp);
    } else {
        *params.total += my_printf("e-%02d", - info.exp);
    }
}

void print_exp(va_list args, ca_params_t params)
{
    double n = va_arg(args, double);

    print_exp_core(get_exp(n), params);
}

void print_exp_core_upper(exp_data_t info, ca_params_t params)
{
    *params.total += my_printf("%.6F", info.value);
    if (info.value == 0.0) {
        *params.total += my_putstr("E+00");
        return;
    }
    if (info.exp >= 0) {
        *params.total += my_printf("E+%02d", info.exp);
    } else
        *params.total += my_printf("E-%02d", - info.exp);
}

void print_exp_upper(va_list args, ca_params_t params)
{
    double n = va_arg(args, double);

    print_exp_core_upper(get_exp(n), params);
}
