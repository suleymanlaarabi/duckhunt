/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../../include/engine.h"

sfText *create_texte(char const *str, engine_t *engine)
{
    sfText *text = sfText_create();

    sfText_setFont(text, engine->assets_server->font);
    sfText_setString(text, str);
    sfText_setScale(text, (sfVector2f) {1.5, 1.5});
    return text;
}
