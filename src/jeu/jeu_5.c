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

all *jeu_gestion_event(all * all)
{
    all = jeu_gestion_event_close(all);
    jeu_gestion_event_jump(all);
    jeu_gestion_event_slash(all);
    jeu_gestion_event_pause_1(all);
    all = jeu_gestion_event_pause_2_1(all);
    return (all);
}

void jeu_move_object(all *all)
{
    move_objectx(all->skytwo, -all->lol, all->lol, 0);
    move_objectx(all->vegtwo, -all->lol, all->lol, 0);
    move_objectx(all->groundtwo, -all->lol, all->lol, 0);
    move_objectx(all->sky, -all->lol, all->lol, 0);
    move_objectx(all->veg, -all->lol, all->lol, 0);
    move_objectx(all->ground, -all->lol, all->lol, 0);
    all = move_objectmassx(all);
    move_objectx(all->monster, -65 * 2.75, 1948, 1);
    move_objectx(all->spike, -51, 1980, 1);
}

void jeu_move_create_map_3(all *all)
{
    if (all->pillar_m != NULL) {
        all->pillar_m->next = malloc(sizeof(multi_object));
        all->pillar_m->next->object = create_object(NULL
        , create_vect((all->countplacemap * 75) - all->longeur_parcourue, 670)
        , create_rect(0, 0, 75, 150), create_speed(all->veg->speed.x * 8, 0));
        sfSprite_setTexture(all->pillar_m->next->object->Sprite
        , all->pillartext, sfTrue);
        all->pillar_m->next->next = NULL;
        all->pillar_m->next->type = 3;
    } else {
        jeu_move_create_map_3_1(all);
    }
}

void jeu_move_create_map_1(all *all)
{
    if (all->pillar_m != NULL) {
        all->pillar_m->next = malloc(sizeof(multi_object));
        all->pillar_m->next->object = create_object("ressource/endflag.png"
        , create_vect((all->countplacemap * 75) - all->longeur_parcourue, 620)
        , create_rect(0, 0, 200, 200), create_speed(all->veg->speed.x * 8, 0));
        all->pillar_m->next->next = NULL;
        all->pillar_m->next->type = 1;
        all->breakmap = 1;
    } else {
        all->pillar_m = malloc(sizeof(multi_object));
        all->pillar_m->object = create_object("ressource/endflag.png"
        , create_vect((all->countplacemap * 75) - all->longeur_parcourue, 620)
        , create_rect(0, 0, 200, 200), create_speed(all->veg->speed.x * 8, 0));
        all->pillar_m->next = NULL;
        all->pillar_m->type = 1;
        all->breakmap = 1;
        all->save = all->pillar_m;
    }
}

void jeu_move_create_map_2(all *all)
{
    if (all->pillar_m != NULL) {
        all->pillar_m->next = malloc(sizeof(multi_object));
        all->pillar_m->next->object = create_object(NULL
        , create_vect((all->countplacemap * 75) - all->longeur_parcourue, 745)
        , create_rect(0, 0, 75, 80), create_speed(all->veg->speed.x * 8, 0));
        sfSprite_setTexture(all->pillar_m->next->object->Sprite
        , all->spike->Texture, sfTrue);
        all->pillar_m->next->next = NULL;
        all->pillar_m->next->type = 2;
    } else {
        all->pillar_m = malloc(sizeof(multi_object));
        all->pillar_m->object = create_object(NULL
        , create_vect((all->countplacemap * 75) - all->longeur_parcourue, 745)
        , create_rect(0, 0, 75, 80), create_speed(all->veg->speed.x * 8, 0));
        sfSprite_setTexture(all->pillar_m->object->Sprite
        , all->spike->Texture, sfTrue);
        all->pillar_m->next = NULL;
        all->pillar_m->type = 2;
        all->save = all->pillar_m;
    }
}