/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** print_float
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <stddef.h>

void put_total(va_list args, ca_params_t params)
{
    int *total = va_arg(args, int *);

    *total = *params.total;
}
