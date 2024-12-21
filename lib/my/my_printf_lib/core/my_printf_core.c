/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int validate_flag(
    char const *str,
    flag_data_t *flags,
    ca_params_t params,
    va_list args)
{
    for (int f = 0; f != 19; f++) {
        if (my_strncmp(flags[f].flag, str, my_strlen(flags[f].flag)) == 0) {
            params.specifier = malloc(sizeof(char) * params.specifier_len);
            my_strncpy(
                params.specifier,
                params.str + 1,
                params.specifier_len - 1);
            flags[f].func(args, params);
            free(params.specifier);
            *params.skip += my_strlen(flags[f].flag) - 1;
            return 1;
        }
    }
    return 0;
}

void skip_check(
    ca_params_t params,
    va_list args)
{
    flag_data_t flags[19] = {
        {"ld", &print_long_number}, {"lx", &print_long_hexa},
        {"s", &print_str}, {"x", &print_hexa},
        {"d", &print_number}, {"i", &print_number},
        {"c", &print_char}, {"o", &print_octal},
        {"u", &print_uint}, {"f", &print_float},
        {"X", &print_hexa_upper}, {"F", &print_float_upper},
        {"g", &print_float}, {"p", &print_pointer},
        {"C", &print_char}, {"lld", &print_long_number},
        {"e", &print_exp}, {"E", &print_exp_upper},
        {"n", &put_total}};

    for (int i = 1; params.str[i] != '\0'; i++) {
        params.specifier_len = i;
        if (validate_flag(&params.str[i], flags, params, args) == 1) {
            *params.skip += i;
            break;
        }
    }
}

int dbl_percent_case(char const *str, int *skip)
{
    if (my_strncmp("%%", str, 2) == 0) {
        my_putchar('%');
        *skip += 1;
        return 1;
    }
    return 0;
}

short has_specifier(ca_params_t params)
{
    if (params.specifier == NULL || params.specifier[0] == '\0')
        return 0;
    return 1;
}
