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

void desactmusic(all* all)
{
    if (all->acitvesound == 0) {
        sfMusic_pause(all->runsound);
    }
    if (sfMusic_getStatus(all->jumplandsound) == sfPlaying) {
        sfMusic_pause(all->jumplandsound);
    }
    if (sfMusic_getStatus(all->slashsound) == sfPlaying) {
        sfMusic_pause(all->slashsound);
    }
    if (sfMusic_getStatus(all->mobdeathsound) == sfPlaying) {
        sfMusic_pause(all->mobdeathsound);
    }
}

void activemusic(all* all)
{
    if (all->acitvesound == 0) {
        sfMusic_play(all->runsound);
    }
    if (sfMusic_getStatus(all->jumplandsound) == sfPaused) {
        sfMusic_play(all->jumplandsound);
    }
    if (sfMusic_getStatus(all->slashsound) == sfPaused) {
        sfMusic_play(all->slashsound);
    }
    if (sfMusic_getStatus(all->mobdeathsound) == sfPaused) {
        sfMusic_play(all->mobdeathsound);
    }
}

void jeu_move_create_map_3_1(all *all)
{
    all->pillar_m = malloc(sizeof(multi_object));
    all->pillar_m->object = create_object(NULL
    , create_vect((all->countplacemap * 75) - all->longeur_parcourue, 670)
    , create_rect(0, 0, 75, 150), create_speed(all->veg->speed.x * 8, 0));
    sfSprite_setTexture(all->pillar_m->object->Sprite
    , all->pillartext, sfTrue);
    all->pillar_m->next = NULL;
    all->pillar_m->type = 3;
    all->save = all->pillar_m;
}