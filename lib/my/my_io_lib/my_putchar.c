/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
