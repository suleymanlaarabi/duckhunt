/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <stdarg.h>
#include <limits.h>
#include "../include/my_printf.h"
#include "../include/my.h"
#include <stddef.h>

int my_printf(char const *format, ...)
{
    va_list args;
    int skip = 0;
    int total = 0;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        skip = 0;
        if (dbl_percent_case(&format[i], &skip) == 0 && format[i] == '%')
            skip_check(
                (ca_params_t) {&format[i], &total, &skip, NULL, 0}, args);
        if (skip != 0) {
            i += skip;
        } else {
            my_putchar(format[i]);
            total++;
        }
    }
    va_end(args);
    return total;
}
