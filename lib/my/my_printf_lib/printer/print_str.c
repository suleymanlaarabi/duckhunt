/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** print_float
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

int setup_print_str(
    unsigned long *len,
    start_end_info_t *info,
    ca_params_t params,
    char const *str
)
{
    if (str == NULL) {
        *params.total += my_putstr("(null)");
        return 0;
    }
    *len = my_strlen(str) - 1;
    *info = my_str_include(&params.specifier[0], ".");
    return 1;
}

static unsigned long get_str_specifier_value(
    char *str,
    ca_params_t params,
    start_end_info_t *info,
    long star_value
)
{
    unsigned long len = my_strlen(str) - 1;
    unsigned long space = 0;

    if (has_specifier(params) && info->start != -1) {
        if (star_value != -1 && (star_value <= (long) len)) {
            str[star_value] = '\0';
            space = len - (star_value - 1);
        }
        if (star_value == -1 &&
            my_getnbr(&params.specifier[info->start]) <= (long) len) {
            str[my_getnbr(&params.specifier[info->start])] = '\0';
            space = len - (my_getnbr(&params.specifier[info->start]) - 1);
        }
    }
    return space;
}

long get_star_value(va_list args, ca_params_t params)
{
    start_end_info_t star_info = my_str_include(params.specifier, "*");

    if (star_info.start != -1 && star_info.end != -1)
        return va_arg(args, long);
    return -1;
}

void print_str(va_list args, ca_params_t params)
{
    long st_v = get_star_value(args, params);
    char *str = my_strdup(va_arg(args, char *));
    unsigned long len = 0;
    start_end_info_t info = {0, 0};
    unsigned long space = 0;

    if (setup_print_str(&len, &info, params, str) == 0)
        return;
    space = get_str_specifier_value(str, params, &info, st_v);
    if (specifier_not_has(params, '-') && params.specifier[0] != '.')
        print_count((ST_OR_NBR(0) - len - 1) + space, ' ');
    *params.total += my_putstr(str);
    if (has_specifier(params) && !specifier_not_has(params, '-'))
        print_count((ST_OR_NBR(1) - 1 - len) + space, ' ');
    free(str);
}
