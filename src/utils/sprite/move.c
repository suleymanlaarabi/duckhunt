/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "utils.h"
#include <math.h>

void move_by_rotation(sfSprite *sprite, int speed)
{
    float radiant = sfSprite_getRotation(sprite);
    sfVector2f movement = {
        cos(radiant) * speed,
        sin(radiant) * speed
    };

    sfSprite_move(sprite, movement);
}

void move_by_vec(sfSprite *sprite, float speed, sfVector2f vec)
{
    vec.x *= speed;
    vec.y *= speed;
    sfSprite_move(sprite, vec);
}

sfVector2f get_vec_from_rad(double rad, float speed)
{
    sfVector2f movement = {
        cos(rad) * speed,
        sin(rad) * speed
    };

    return movement;
}
