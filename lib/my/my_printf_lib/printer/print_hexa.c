/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** print_float
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stddef.h>
#include <limits.h>

void print_long_hexa(va_list args, ca_params_t params)
{
    unsigned long n = va_arg(args, unsigned long);
    char s[100] = "\0";
    int i = 0;

    for (int t = 0; n > 0; i++) {
        t = n % 16;
        if (t >= 10) {
            s[i] = t + 87;
        } else
            s[i] = t + 48;
        n /= 16;
    }
    s[i] = '\0';
    my_revstr(s);
    *params.total += my_strlen(s);
    my_putstr(s);
}

int special_hexa_case(long n, ca_params_t params)
{
    if (n >= LONG_MAX) {
        my_putstr("ffffffff");
        *params.total += 8;
        return 1;
    } else if (n <= LONG_MAX * -1) {
        my_putchar('1');
        *params.total += 1;
        return 1;
    }
    return 0;
}

void print_hexa(va_list args, ca_params_t params)
{
    long n = va_arg(args, long);
    char s[100] = "\0";
    int i = 0;

    if (special_hexa_case(n, params) == 1)
        return;
    for (int t = 0; n > 0; i++) {
        t = n % 16;
        if (t >= 10) {
            s[i] = t + 87;
        } else
            s[i] = t + 48;
        n /= 16;
    }
    s[i] = '\0';
    my_revstr(s);
    *params.total += my_strlen(s);
    my_putstr(s);
}

void print_hexa_upper(va_list args, ca_params_t params)
{
    long n = va_arg(args, long);
    char s[100] = "\0";
    int i = 0;

    if (special_hexa_case(n, params) == 1)
        return;
    for (int t = 0; n > 0; i++) {
        t = n % 16;
        if (t >= 10) {
            s[i] = t + 55;
        } else
            s[i] = t + 48;
        n /= 16;
    }
    s[i] = '\0';
    my_revstr(s);
    *params.total += my_strlen(s);
    my_putstr(s);
}
