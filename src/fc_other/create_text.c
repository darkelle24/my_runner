/*
** EPITECH PROJECT, 2019
** create_text.c
** File description:
** create_text.c
*/

#include <SFML/Graphics.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include "../../include/my.h"

text *create_text(char *valeur, sfVector2f position, int police, sfFont *font)
{
    sfText *message = sfText_create();
    text *textprint = malloc(sizeof(textprint));

    textprint->text = message;
    textprint->valeur = valeur;
    textprint->position = position;
    sfText_setPosition(message, position);
    sfText_setFont(message, font);
    sfText_setCharacterSize(message, police);
    sfText_setColor(message, sfBlack);
    sfText_setString(message, valeur);
    return (textprint);
}