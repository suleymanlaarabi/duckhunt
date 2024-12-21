/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfVector2f sub_vector2f(sfVector2f first, sfVector2f second)
{
    first.x -= second.x;
    first.y -= second.y;
    return first;
}

sfVector2f ext_vector2f(sfVector2f v, float scale)
{
    return (sfVector2f) {v.x * scale, v.y * scale};
}

sfVector2i ext_vector2i(sfVector2i v, sfVector2u y)
{
    return (sfVector2i) {v.x * y.x, v.y * y.x};
}

sfVector2f from_vecu(sfVector2u v)
{
    return (sfVector2f) {v.x, v.y};
}
