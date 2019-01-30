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

void jeu_map_gestion_player_run_on_pillar(all *all)
{
    all->tomb = 0;
    all->jumpforce = 0;
    all->jump = -1;
    all->pillar_m = all->save;
    while (all->pillar_m != NULL
    && all->pillar_m->object->Position.x <= 300 && all->tomb == 0) {
        if (hitbox_pillar_test_run(all) == 1) {
            all->jump = 0;
            all->tomb = 1;
            all->pillarrun = all->pillar_m->object;
            all->runman->Position.y = 480;
        }
        all->pillar_m = all->pillar_m->next;
    }
}

int hitbox_pillar_recept_on_pillar(all *all)
{
    if (((all->runman->Position.x + 127
    <= all->pillar_m->object->Position.x + 50
    && all->runman->Position.x + 127 >= all->pillar_m->object->Position.x)
    || (all->runman->Position.x + 116 <= all->pillar_m->object->Position.x + 50
    && all->runman->Position.x + 116 >= all->pillar_m->object->Position.x)
    || (all->runman->Position.x + 210 <= all->pillar_m->object->Position.x + 50
    && all->runman->Position.x + 210 >= all->pillar_m->object->Position.x))
    && (all->runman->Position.y + 312 * 0.65
    <= all->pillar_m->object->Position.y + 15
    && all->runman->Position.y + 312 * 0.65
    >= all->pillar_m->object->Position.y)
    && all->jump == -1 && all->pillar_m->type == 3) {
        return (1);
    }
    return (0);
}

void jeu_map_gestion_player_recept_on_pillar(all *all)
{
    while (all->pillar_m != NULL
    && all->pillar_m->object->Position.x <= 350 && all->tomb == 0) {
        if (hitbox_pillar_recept_on_pillar(all) == 1) {
            all->jump = 0;
            all->compt = 0;
            all->tomb = 1;
            all->timeanim = all->timeinit;
            all->runman->Position.y = 480;
            all->pillarrun = all->pillar_m->object;
            sfMusic_play(all->jumplandsound);
        }
        all->pillar_m = all->pillar_m->next;
    }
}

void jeu_map_gestion_player_jump(all *all)
{
    all->runman->Position.y -= all->jumpforce * all->jump;
    all->jumpforce -= all->g * all->jump;
    if (all->jump == -1) {
        if (all->runman->Position.y >= 630) {
            all->jump = 0;
            all->compt = 0;
            all->timeanim = all->timeinit;
            all->runman->Position.y = 630;
            sfMusic_play(all->jumplandsound);
        } else {
            all->pillar_m = all->save;
            jeu_map_gestion_player_recept_on_pillar(all);
        }
    }
}

void jeu_map_gestion_player_win(all *all)
{
    if (((all->runman->Position.x + 110
    <= all->pillar_m->object->Position.x + 30
    && all->runman->Position.x + 110 >= all->pillar_m->object->Position.x))) {
        all->score += 300;
        write(1, "Win with ", 9);
        my_put_nbr(all->score);
        write(1, " score\n", 7);
        all->pass = 1;
    }
}