/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <stdlib.h>

int random_between(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
