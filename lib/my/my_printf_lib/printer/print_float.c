/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** print_float
*/

#include "../../include/my.h"
#include "../../include/my_math.h"
#include "../../include/my_printf.h"

static int print_float_special_case(double value, short is_upper)
{
    if (value == MY_INFINITY)
        return my_putstr(is_upper ? "INF" : "inf");
    if (value == - MY_INFINITY)
        return my_putstr(is_upper ? "-INF" : "-inf");
    if (MY_ISNAN(value))
        return my_putstr(is_upper ? "NAN" : "nan");
    return -1;
}

static int get_float_space(double n, int precision, padding_value_t info)
{
    int mag = 0;
    int space = 0;

    mag += (count_zero((long) n) + 1) + precision;
    if (precision != 0)
        mag += 1;
    space = info.value - mag;
    if (n < 0)
        space -= 1;
    return space;
}

static int check_special_case(double value, int is_upper, ca_params_t params)
{
    if (print_float_special_case(value, is_upper) != -1) {
        *params.total += 3;
        return 1;
    }
    return 0;
}

static void print_float_core(va_list args, ca_params_t params, int is_upper)
{
    padding_value_t padding_info = get_padding_info(params, args);
    int precision = get_precision_specifier(params, args);
    double value = va_arg(args, double);
    int space = get_float_space(MY_ABS(value), precision, padding_info);

    if (precision == -1)
        precision = 6;
    if (MY_SIGNBIT(value) && padding_info.c == '0')
        *params.total += my_putchar('-');
    if (check_special_case(value, is_upper, params) == 1)
        return;
    if (padding_info.c != '0')
        padding_info.c = ' ';
    if (params.specifier[0] != '-')
        *params.total += print_count(space, padding_info.c);
    if (padding_info.c != '0' && MY_SIGNBIT(value))
        *params.total += my_putchar('-');
    *params.total += print_all_part(
        MY_ABS(value), precision == -1 ? 6 : precision);
}

void print_float(va_list args, ca_params_t params)
{
    print_float_core(args, params, 0);
}

void print_float_upper(va_list args, ca_params_t params)
{
    print_float_core(args, params, 1);
}
