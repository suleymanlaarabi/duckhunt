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

// return 1 if specifier with the char else 0
int specifier_not_has(ca_params_t params, char c)
{
    if (has_specifier(params) && params.specifier[0] != c)
        return 1;
    return 0;
}

// update number negative number to positive
// and update is_neg to 1 if is negative
void update_neg(int *number, int *is_neg)
{
    if (*number < 0) {
        *is_neg = 1;
        *number = (*number) * -1;
    } else {
        *is_neg = 0;
    }
}

// return -1 if precision not finded else return precision value
int get_precision_specifier(ca_params_t params, va_list args)
{
    start_end_info_t info = {-1, -1};

    if (!has_specifier(params))
        return -1;
    info = my_str_include(params.specifier, ".");
    if (info.start != -1 && info.end != -1) {
        if (params.specifier[info.start + 1] != '*') {
            return my_getnbr(&params.specifier[info.start]);
        } else {
            return va_arg(args, int);
        }
    }
    return -1;
}

// return 0 if plus specifier not finded else return 1
int get_plus_specifier(ca_params_t params)
{
    if (!has_specifier(params))
        return 0;
    if (params.specifier[0] == '+')
        return 1;
    return 0;
}

static int get_first_number_index(char const *str)
{
    int i = 0;

    if (is_num(str[0]))
        return 1;
    while (str[i] != '\0' && !is_num(str[i])) {
        i++;
    }
    if (is_num(str[i]))
        return i;
    return -1;
}

// return an array with the char of the specifier
// and the value of the specifier (-1 if not padding specifier)
// {char character, int value}
padding_value_t get_padding_specifier(ca_params_t p)
{
    padding_value_t info = {-1, -1};

    if (has_specifier(p) && get_first_number_index(p.specifier) > 0) {
        info.c = p.specifier[0];
        info.value = my_getnbr(p.specifier);
    }
    return info;
}
