/*
** EPITECH PROJECT, 2019
** jeu.c
** File description:
** jeu.c
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

void jeu_gestion_event_jump(all *all)
{
    if (all->event.key.code == sfKeySpace
    && all->jump == 0 && all->pause == 0) {
        all->jump = 1;
        all->compt = 0;
        all->timeanim = 16666;
        if (all->slash != 0)
            sfMusic_stop(all->slashsound);
        all->slash = 0;
        all->jumpforce = all->jumpforceinit;
        all->pointhaut = calcultemp(all->timeanim,
        all->jumpforceinit, all->g, 29);
        all->tomb = 0;
        all->acitvesound = 1;
        sfMusic_stop(all->runsound);
        sfClock_restart(all->animejump);
    }
}

void jeu_gestion_event_slash(all *all)
{
    if (all->event.type == sfEvtMouseButtonReleased &&
    all->event.mouseButton.button == sfMouseLeft && all->jump == 0
    && all->slash == 0 && all->pause == 0) {
        all->compt = 0;
        sfMusic_play(all->slashsound);
        all->timeanim = 8666;
        all->slash = 1;
    }
}

void jeu_gestion_event_pause_1(all *all)
{
    if (all->event.type == sfEvtKeyPressed
    && (all->event.key.code == sfKeyEscape || all->event.key.code == sfKeyP)) {
        if (all->pause == 0) {
            all->pause = 1;
            desactmusic(all);
        } else {
            all->pause = 0;
            activemusic(all);
        }
    }
}

void jeu_gestion_event_pause_2_2(all *all)
{
    if (all->event.mouseButton.x >= 720
    && all->event.mouseButton.x <= 720 + 480
    && all->event.mouseButton.y >= 400 &&
    all->event.mouseButton.y <= 400 + 50) {
        all->pause = 0;
        activemusic(all);
    }
}

all *jeu_gestion_event_pause_2_1(all *all)
{
    if (all->pause == 1) {
        if (all->event.type == sfEvtMouseButtonReleased &&
        all->event.mouseButton.button == sfMouseLeft) {
            jeu_gestion_event_pause_2_2(all);
            if (all->event.mouseButton.x >= 720
            && all->event.mouseButton.x <= 720 + 480
            && all->event.mouseButton.y >= 521 &&
            all->event.mouseButton.y <= 521 + 50) {
                all->pause = 0;
                sfRenderWindow_close(all->window);
                all->exit = 1;
            }
        }
    }
    return (all);
}