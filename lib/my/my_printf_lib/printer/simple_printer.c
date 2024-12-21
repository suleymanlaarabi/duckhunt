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

void print_uint(va_list args, ca_params_t params)
{
    unsigned int n = va_arg(args, unsigned int);

    *params.total += my_put_nbr(n);
}

void print_char(va_list args, ca_params_t params)
{
    my_putchar(va_arg(args, int));
    *params.total += 1;
}
