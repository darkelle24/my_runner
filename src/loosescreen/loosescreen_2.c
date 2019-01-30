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

void loosescreen_3(loose_s *loosevar)
{
    if (loosevar->event.mouseButton.x >= 47
    && loosevar->event.mouseButton.x <= 47 + 490
    && loosevar->event.mouseButton.y >= 875 &&
    loosevar->event.mouseButton.y <= 875 + 80 && loosevar->pass != 1) {
            sfRenderWindow_close(loosevar->window);
            loosevar->exit = 1;
            destroy_object(loosevar->menu, 1, NULL);
    }
    if (loosevar->event.mouseButton.x >= 1391
    && loosevar->event.mouseButton.x <= 1391 + 490
    && loosevar->event.mouseButton.y >= 879 && loosevar->event.mouseButton.y
    <= 879 + 80 && loosevar->pass != 1) {
        destroy_object(loosevar->menu, 1, NULL);
        jeumap(loosevar->window, loosevar->map);
        loosevar->exit = 1;
    }
}

void loosescreen_4(loose_s *loosevar)
{
    if (loosevar->event.mouseButton.x >= 860
    && loosevar->event.mouseButton.x <= 860 + 233
    && loosevar->event.mouseButton.y >= 899 &&
    loosevar->event.mouseButton.y <= 899 + 38 && loosevar->pass != 1) {
        loosevar->list = loosevar->backup;
        loosevar->count = 0;
        while (loosevar->count < 10) {
            loosevar->list->name = "           ";
            loosevar->list->score = 0;
            sfText_setString(loosevar->scorename[loosevar->count]->text
            , loosevar->list->name);
            sfText_setString(loosevar->scoretext[loosevar->count]->text
            , longtochar(loosevar->list->score));
            loosevar->count++;
            loosevar->list = loosevar->list->next;
        }
        loosevar->list = loosevar->backup;
        save(loosevar->list);
    }
}

void loosescreen_5_1(loose_s *loosevar)
{
    loosevar->pass = 0;
    loosevar->list = loosevar->backup;
    loosevar->count = 1;
    while (loosevar->score < loosevar->list->score) {
        loosevar->count++;
        loosevar->after = loosevar->list;
        loosevar->list = loosevar->list->next;
    }
    loosevar->news->rank = loosevar->count;
    loosevar->news->name = loosevar->buffer;
    loosevar->news->score = loosevar->score;
}

void loosescreen_5_2(loose_s *loosevar)
{
    if (loosevar->count != 10) {
        loosevar->news->next = loosevar->list;
    } else
        loosevar->news->next = NULL;
    if (loosevar->count != 1) {
        loosevar->after->next = loosevar->news;
    } else
        loosevar->backup = loosevar->news;
    while (loosevar->list != NULL) {
        loosevar->list->rank++;
        if (loosevar->list->next == NULL && loosevar->count != 10) {
            loosevar->after->next = NULL;
            free(loosevar->list->name);
            free(loosevar->list);
        }
        loosevar->after = loosevar->list;
        loosevar->list = loosevar->list->next;
    }
}

void loosescreen_5_3(loose_s *loosevar)
{
    while (loosevar->count < 10) {
        sfText_setString(loosevar->scorename[loosevar->count]->text
        , loosevar->list->name);
        sfText_setString(loosevar->scoretext[loosevar->count]->text
        , longtochar(loosevar->list->score));
        loosevar->count++;
        loosevar->list = loosevar->list->next;
    }
}