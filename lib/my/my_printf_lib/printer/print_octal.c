/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** printer
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stdarg.h>

void print_octal(va_list args, ca_params_t params)
{
    unsigned long n = va_arg(args, unsigned long);
    char s[100] = "\0";
    int i = 0;

    for (int t = 0; n > 0; i++) {
        t = n % 8;
        s[i] = t + 48;
        n /= 8;
    }
    s[i] = '\0';
    my_revstr(s);
    *params.total += my_strlen(s);
    my_putstr(s);
}
