/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init.c
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
#include "../../include/macro.h"

all *init3_1(all *everything)
{
    everything->sky = create_object
    ("ressource/Sky_back_layer.png", create_vect(0, 0)
    , create_rect(0, 0, 1920, 1080), create_speed(everything->vitesse, 0));
    everything->veg = create_object
    ("ressource/montagne.png", create_vect(0, 510)
    , create_rect(0, 0, 1920, 503), create_speed
    (everything->sky->speed.x * 2, 0));
    everything->ground = create_object
    ("ressource/mdr.png", create_vect(0, 783)
    , create_rect(0, 0, 1920, 298), create_speed
    (everything->veg->speed.x * 8, 0));
    everything->skytwo = create_object
    ("ressource/Sky_back_layer.png", create_vect(1920, 0)
    , create_rect(0, 0, 1920, 1080), create_speed(everything->vitesse, 0));
    return (everything);
}

all *init3(all *everything)
{
    char filepathrun[35] = "ressource/Running/Running_000.png";

    everything = init3_1(everything);
    everything->vegtwo = create_object
    ("ressource/montagne.png", create_vect(1920, 510)
    , create_rect(0, 0, 1920, 503)
    , create_speed(everything->sky->speed.x * 2, 0));
    everything->groundtwo = create_object
    ("ressource/mdr.png", create_vect(1920, 783)
    , create_rect(0, 0, 1920, 298), create_speed
    (everything->veg->speed.x * 8, 0));
    everything->runman = create_object(filepathrun, create_vect(40, 630)
    , create_rect(0, 0, 398, 312), create_speed(0, 0));
    everything = init4(everything);
    return (everything);
}

all *init2_1(all *everything)
{
    everything->music = sfMusic_createFromFile
    ("ressource/Sound/91476_Glorious_morning.ogg");
    everything->runsound = sfMusic_createFromFile
    ("ressource/Sound/running.ogg");
    everything->jumplandsound = sfMusic_createFromFile
    ("ressource/Sound/jumpland.ogg");
    everything->slashsound = sfMusic_createFromFile
    ("ressource/Sound/sabre.ogg");
    everything->mobdeathsound = sfMusic_createFromFile
    ("ressource/Sound/mobdeath.ogg");
    everything->font = sfFont_createFromFile
    ("ressource/DejaVuSansMono.ttf");
    return (everything);
}

all *init2(all *everything)
{
    everything = init2_1(everything);
    everything->scoretext = create_text(longtochar
    (everything->score), create_vect(240, 53), 44, everything->font);
    everything->clock = sfClock_create();
    everything->anime = sfClock_create();
    everything->animejump = sfClock_create();
    everything->scoreclock = sfClock_create();
    everything->animmonster = sfClock_create();
    everything->avance = 75;
    everything = init3(everything);
    return (everything);
}

all *init1()
{
    all *everything = malloc(sizeof(all));

    everything->vitesse = SPEED;
    everything->lol = 1910;
    everything->compt = 0;
    everything->jump = 0;
    everything->comptmonstre = 0;
    everything->slash = 0;
    everything->tomb = 0;
    everything->score = 0;
    everything->jumpforceinit = JUMPFORCEINIT;
    everything->g = GRAVITY;
    everything->timeinit = 15000;
    everything->timeanim = 15000;
    everything->pause = 0;
    everything->acitvesound = 100;
    everything->pointhaut = calcultemp(everything->timeanim
    , everything->jumpforceinit, everything->g, 29);
    everything = init2(everything);
    return (everything);
}