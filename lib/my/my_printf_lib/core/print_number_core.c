/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** print_number_core
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include "../../include/my_math.h"
#include <stdarg.h>


int get_padding_value(ca_params_t params, va_list args)
{
    if (!has_specifier(params))
        return 0;
    if (my_str_include_before(params.specifier, "*", '.') != 0) {
        return va_arg(args, int);
    }
    return MY_ABS(my_getnbr(params.specifier));
}

padding_value_t get_padding_info(ca_params_t params, va_list args)
{
    padding_value_t info = {0, 0};

    if (has_specifier(params) && params.specifier[0] != '.') {
        info.c = params.specifier[0];
        info.value = get_padding_value(params, args);
    }
    return info;
}

int get_space_count(
    padding_value_t *info,
    int number)
{
    int space = 0;
    int number_magnitude = count_zero(number) + 1;

    space = info->value - number_magnitude;
    return space;
}
