/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stddef.h>
#include "../include/my_getnbr.h"

static short is_number(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

detect_info_t get_info(char const *str)
{
    detect_info_t info = {0, 0, 0};

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && is_number(str[i + 1])) {
            info.index = i + 1;
            info.is_neg = 1;
            info.is_detected = 1;
            return info;
        }
        if (is_number(str[i]) == 1) {
            info.index = i;
            info.is_neg = 0;
            info.is_detected = 1;
            return info;
        }
    }
    return info;
}

static int get_last_index(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (is_number(str[i])) {
        i++;
    }
    return i;
}

static int parse_number(int end, char const *str, int factor)
{
    int result = 0;

    for (int i = 0; i != end; i++) {
        result += (str[i] - 48) * factor;
        factor = factor / 10;
    }
    return result;
}

long my_getnbr(char const *str)
{
    detect_info_t info = get_info(str);
    int last_index = 0;
    int factor = 0;
    int result = 0;

    if (str == NULL)
        return 0;
    if (info.is_detected == 0)
        return 0;
    last_index = get_last_index(&str[info.index]) + info.index;
    factor = my_compute_power_rec(10, (last_index - info.index) - 1);
    result = parse_number(
        last_index - info.index, &str[info.index], factor);
    if (info.is_neg)
        return result * -1;
    return result;
}
