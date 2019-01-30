/*
** EPITECH PROJECT, 2018
** lol
** File description:
** lol
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

void destroy2(all* all)
{
    destroy_object(all->pauseback, 1, NULL);
    destroy_object(all->veg, 1, NULL);
    destroy_object(all->monster, 4, all->monstertext);
    destroy_object(all->ground, 1, NULL);
    sfText_destroy(all->scoretext->text);
    sfFont_destroy(all->font);
    sfMusic_destroy(all->music);
    sfMusic_destroy(all->runsound);
    sfMusic_destroy(all->slashsound);
    sfMusic_destroy(all->mobdeathsound);
    sfMusic_destroy(all->jumplandsound);
    sfClock_destroy(all->clock);
    sfClock_destroy(all->scoreclock);
    sfClock_destroy(all->anime);
    free(all);
}

void destroy1(all* all)
{
    destroy_object(all->sky, 1, NULL);
    destroy_object(all->skytwo, 1, NULL);
    destroy_object(all->vegtwo, 1, NULL);
    destroy_object(all->groundtwo, 1, NULL);
    destroy_object(all->runman, 24, all->runtext);
    destroy_texturearray(40, all->jumptext);
    destroy_texturearray(24, all->slashrun);
    destroy_object(all->spike, 1, NULL);
    destroy_object(all->pillar, 1, NULL);
    destroy_object(all->scoreimage, 1, NULL);
    destroy2(all);
}

void destroy1spe(all* all)
{
    int count = 0;

    while (all->pillar_m != NULL) {
        destroy_object(all->pillar_m->object, 1, NULL);
        all->pillar_m = all->pillar_m->next;
    }
    destroy1(all);
}