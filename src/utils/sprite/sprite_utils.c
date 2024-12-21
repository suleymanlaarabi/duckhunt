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

void flip_sprite(sfSprite *sprite)
{
    sfVector2f scale = sfSprite_getScale(sprite);

    sfSprite_setScale(sprite, (sfVector2f) {scale.x * -1, scale.y});
}

sfBool is_flipped(sfSprite *sprite)
{
    sfVector2f scale = sfSprite_getScale(sprite);

    if (scale.x < 0)
        return sfTrue;
    return sfFalse;
}

void move_by_rotation_to(sfSprite *sprite, sfVector2f to, int speed)
{
    sfVector2f position = sfSprite_getPosition(sprite);
    sfVector2f direction = sub_vector2f(
        to, position);
    double radiant = atan2(direction.y, direction.x);

    sfSprite_move(
        sprite, (sfVector2f) {cos(radiant) * speed, sin(radiant) * speed});
}
