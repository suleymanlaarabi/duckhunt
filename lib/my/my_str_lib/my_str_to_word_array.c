/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stddef.h>
#include <stdlib.h>

short detect_alphanum(char c)
{
    return ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'));
}

static int word_to_next_notalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && detect_alphanum(str[i]) == 1)
        i++;
    return i;
}

int count_word(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\0' && detect_alphanum(str[i]) == 1) {
            i += word_to_next_notalpha(&str[i]) - 1;
            len++;
        } else {
            continue;
        }
    }
    return len;
}

char **my_str_to_word_array(char const *str)
{
    int len = count_word(str);
    int word_count = 0;
    char **array = 0;
    int size = 0;

    if (my_strlen(str) == 0 || len == 0)
        return NULL;
    array = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; word_count < len; i++) {
        if (detect_alphanum(str[i]) == 1) {
            size = word_to_next_notalpha(&str[i]);
            array[word_count] = malloc(sizeof(char) * (size + 1));
            array[word_count][size] = '\0';
            my_strncpy(array[word_count], &str[i], size);
            word_count++;
            i += size - 1;
        }
    }
    array[len] = NULL;
    return array;
}
