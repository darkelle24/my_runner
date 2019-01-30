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

void loosescreen_5(loose_s *loosevar)
{
    if (((loosevar->event.mouseButton.x >= 758
    && loosevar->event.mouseButton.x <= 758 + 402
    && loosevar->event.mouseButton.y >= 611
    && loosevar->event.mouseButton.y <= 611 + 42) ||
    (loosevar->event.type == sfEvtTextEntered
    && loosevar->event.key.code == 13)) && loosevar->pass == 1) {
        loosescreen_5_1(loosevar);
        loosescreen_5_2(loosevar);
        loosevar->list = loosevar->backup;
        loosevar->count = 0;
        loosescreen_5_3(loosevar);
        loosevar->list = loosevar->backup;
        save(loosevar->list);
    }
}

void loosescreen_6(loose_s *loosevar)
{
    if (loosevar->event.type == sfEvtMouseButtonReleased &&
        loosevar->event.mouseButton.button == sfMouseLeft) {
        loosescreen_3(loosevar);
        loosescreen_4(loosevar);
    }
    loosescreen_5(loosevar);
    if (loosevar->event.type == sfEvtTextEntered && loosevar->pass == 1) {
        if (loosevar->event.key.code == 8) {
            loosevar->count2--;
            loosevar->buffer[loosevar->count2] = ' ';
        } else if (loosevar->count2 != 11 && loosevar->event.key.code != 13) {
            loosevar->buffer[loosevar->count2] = loosevar->event.key.code;
            loosevar->count2++;
        }
        sfText_setString(loosevar->name->text, loosevar->buffer);
        if (loosevar->count2 == -1)
            loosevar->count2 = 0;
    }
}

void loosescreen_7(loose_s *loosevar)
{
    while (loosevar->count < 10) {
        sfText_setColor(loosevar->scorename[loosevar->count]->text
        , sfWhite);
        sfText_setColor(loosevar->scoretext[loosevar->count]->text
        , sfWhite);
        sfRenderWindow_drawText(loosevar->window
        , loosevar->scorename[loosevar->count]->text, NULL);
        sfRenderWindow_drawText(loosevar->window
        , loosevar->scoretext[loosevar->count]->text, NULL);
        loosevar->count++;
    }
}

void loosescreen_8(loose_s *loosevar)
{
    if (loosevar->pass == 1) {
        sfRenderWindow_drawSprite(loosevar->window
        , loosevar->entername->Sprite, NULL);
        sfRenderWindow_drawText(loosevar->window, loosevar->name->text, NULL);
    }
}

void loosescreen(sfRenderWindow *window, long long score, char **map)
{
    loose_s *loosevar = initloose(window, score, map);

    initloose_2(loosevar);
    while (sfRenderWindow_isOpen(window) && loosevar->exit == 0) {
        while (sfRenderWindow_pollEvent(window, &loosevar->event)) {
            if (loosevar->event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                loosevar->exit = 1;
            }
            loosescreen_6(loosevar);
        }
        if (loosevar->exit == 0) {
            sfRenderWindow_drawSprite(window, loosevar->menu->Sprite, NULL);
            loosevar->count = 0;
            loosescreen_7(loosevar);
            loosescreen_8(loosevar);
            sfRenderWindow_display(window);
        }
    }
}