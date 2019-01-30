/*
** EPITECH PROJECT, 2019
** loosescreen.c
** File description:
** loosescreen.c
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

char *prepare_buffer()
{
    char *buffer = malloc(sizeof(char) * 12);
    int count = 0;

    while (count < 11) {
        buffer[count] = ' ';
        count++;
    }
    buffer[11] = '\0';
    return (buffer);
}

loose_s *initloose(sfRenderWindow *window, long long score, char **map)
{
    loose_s *loosevar = malloc(sizeof(loose_s));

    loosevar->menu = create_object("ressource/scoreboard.png", create_vect(0, 0)
    , create_rect(0, 0, 1920, 1080), create_speed(0, 0));
    loosevar->list = lecturescore();
    loosevar->buffer = prepare_buffer();
    loosevar->backup = loosevar->list;
    loosevar->news = malloc(sizeof(* loosevar->news));
    loosevar->font = sfFont_createFromFile("ressource/DejaVuSansMono.ttf");
    loosevar->scorename = malloc(sizeof(text *) * 10);
    loosevar->scoretext = malloc(sizeof(text *) * 10);
    loosevar->pass = 0;
    loosevar->count = 0;
    loosevar->count2 = 0;
    loosevar->window = window;
    loosevar->score = score;
    loosevar->map = map;
    loosevar->exit = 0;
    return (loosevar);
}

void initloose_2(loose_s *loosevar)
{
    while (loosevar->count != 10) {
        loosevar->scorename[loosevar->count] = create_text(loosevar->list->name
        , create_vect(640, 210 + (65 * loosevar->count)), 34, loosevar->font);
        loosevar->scoretext[loosevar->count] =
        create_text(longtochar(loosevar->list->score)
        , create_vect(1225, 210 + (65 * loosevar->count)), 34, loosevar->font);
        if (loosevar->list->next == NULL
        && loosevar->score > loosevar->list->score) {
            loosevar->pass = 1;
            loosevar->entername = create_object("ressource/entrez un nom.png"
            , create_vect(706, 291)
            , create_rect(0, 0, 507, 406), create_speed(0, 0));
            loosevar->name = create_text(loosevar->buffer
            , create_vect(777, 437), 50, loosevar->font);
            sfText_setColor(loosevar->name->text, sfWhite);
        }
        loosevar->list = loosevar->list->next;
        loosevar->count++;
    }
}