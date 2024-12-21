/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** print_float
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stddef.h>

void print_pointer(va_list args, ca_params_t params)
{
    my_putchar('0');
    my_putchar('x');
    print_long_hexa(args, params);
}
