/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stddef.h>

sfSprite *sprite_texture_scale(
    char const *path, sfVector2f scale
)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite,
        sfTexture_createFromFile(path, NULL), sfFalse);
    sfSprite_setScale(sprite, scale);
    return sprite;
}
