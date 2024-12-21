/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** printer
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stdarg.h>
#include <stddef.h>

static void get_space_precision(int precision, int space, int number)
{
    if (precision != -1) {
        precision = precision - (count_zero(number) + 1);
        space -= precision;
    }
}

void print_number(va_list args, ca_params_t params)
{
    padding_value_t padding_info = get_padding_info(params, args);
    int precision = get_precision_specifier(params, args);
    int number = va_arg(args, int);
    int space = get_space_count(&padding_info, number);

    get_space_precision(precision, space, number);
    if (padding_info.c == '0' && number == 0)
        space -= 1;
    if (padding_info.c != '-') {
        *params.total += print_count(space, padding_info.c == '0' ? '0' : ' ');
        *params.total += print_count(precision, '0');
    }
    if (params.specifier[0] == '+' && number >= 0)
        *params.total += my_putchar('+');
    *params.total += my_put_nbr(number);
    if (padding_info.c == '-') {
        *params.total += print_count(space, '0');
        *params.total += print_count(space, padding_info.c == '0' ? '0' : ' ');
    }
}
