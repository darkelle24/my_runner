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

void jeu_map_gestion_player_death_pillar(all *all)
{
    if (((all->runman->Position.x + 110
    <= all->pillar_m->object->Position.x + 50
    && all->runman->Position.x + 110
    >= all->pillar_m->object->Position.x))
    && (all->runman->Position.y + 312 * 0.65 > all->pillar->Position.y + 30
    && all->runman->Position.y + 312 * 0.65
    <= all->pillar_m->object->Position.y + 180)) {
        write(1, "Game OVER Pillar\n", 17);
        all->pass = 1;
    }
}

void jeu_map_gestion_player_death_spike(all *all)
{
    if (((all->runman->Position.x + 110
    <= all->pillar_m->object->Position.x + 70
    && all->runman->Position.x + 110
    >= all->pillar_m->object->Position.x))
    && (all->runman->Position.y + 312 * 0.65
    > all->pillar_m->object->Position.y + 20
    && all->runman->Position.y + 312 * 0.65
    <= all->pillar_m->object->Position.y + 180)) {
        write(1, "Game OVER Spike\n", 16);
        all->pass = 1;
    }
}

void jeu_map_gestion_player_death_or_win_2(all *all)
{
    if (all->pillar_m->type == 3) {
        jeu_map_gestion_player_death_pillar(all);
    } else if (all->pillar_m->type == 2) {
        jeu_map_gestion_player_death_spike(all);
    } else
        jeu_map_gestion_player_win(all);
}

void jeu_map_gestion_player_death_or_win_1(all *all)
{
    while (all->pillar_m != NULL && all->pillar_m->object->Position.x <= 300) {
        jeu_map_gestion_player_death_or_win_2(all);
        all->pillar_m = all->pillar_m->next;
    }
    if (((all->runman->Position.x + 110 >= all->monster->Position.x + 17 * 2.75
    && all->runman->Position.x + 100 <= all->monster->Position.x + 40 * 2.75))
    && (all->runman->Position.y + 312 * 0.65 >= all->monster->Position.y + 20
    && all->runman->Position.y + 312 * 0.65
    <= all->monster->Position.y + 42 * 2.75 + 15)) {
        write(1, "Game OVER Monstre\n", 18);
        all->pass = 1;
    }
}

void jeu_map_gestion_player(all *all)
{
    if (all->jump == 0) {
        jeu_map_gestion_player_anim_slash_or_run(all);
        if (all->tomb == 1 && all->runman->Position.x + 30
        > all->pillarrun->Position.x + 50)
            jeu_map_gestion_player_run_on_pillar(all);
    } else {
        jeu_map_gestion_player_jump(all);
        sfSprite_setPosition(all->runman->Sprite, all->runman->Position);
        if (all->jumpforce <= 0 && all->jump == 1) {
            all->jump = -1;
            all->pointhaut = calcultemp(all->timeanim, all->jumpforceinit
            , all->g, 11);
        }
    }
    all->pillar_m = all->save;
    jeu_map_gestion_player_death_or_win_1(all);
    sfClock_restart(all->anime);
}