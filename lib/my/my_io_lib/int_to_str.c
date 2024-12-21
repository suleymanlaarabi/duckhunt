/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stdlib.h>

static void s_final(unsigned long n, char *buf)
{
    unsigned long multiplicator = 1;
    int i = 0;

    while (n / multiplicator > 9)
        multiplicator = multiplicator * 10;
    while (multiplicator > 0) {
        buf[i] = (n / multiplicator) + '0';
        n %= multiplicator;
        multiplicator /= 10;
        i++;
    }
    buf[i] = '\0';
}

char *int_to_str(long n)
{
    char *str = malloc(sizeof(char) * 15);

    if (n == 0) {
        free(str);
        return my_strdup("0");
    } else
        s_final((unsigned long long)n, str);
    return str;
}
