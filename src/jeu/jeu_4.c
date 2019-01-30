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

void jeu_move_create_map(all *all)
{
    if (all->avance <= 0) {
        all->avance = 75;
        if (all->pillar_m != NULL) {
            while (all->pillar_m->next != NULL) {
                all->pillar_m = all->pillar_m->next;
            }
        }
        if (all->map != NULL) {
            if (all->map[9][all->countplacemap] == '3')
                jeu_move_create_map_3(all);
            if (all->map[9][all->countplacemap] == '1')
                jeu_move_create_map_1(all);
            if (all->map[9][all->countplacemap] == '2')
                jeu_move_create_map_2(all);
        } else
            jeu_move_create_map_infini(all);
        all->pillar_m = all->save;
        all->countplacemap++;
    }
}

void jeu_move(all *all)
{
    jeu_move_object(all);
    if (all->breakmap == 0) {
        all->avance += all->groundtwo->speed.x;
        all->longeur_parcourue += all->groundtwo->speed.x * -1;
        jeu_move_create_map(all);
    }
    if (all->slash == 1
    && ((all->runman->Position.x + 150 >= all->monster->Position.x + 19 * 2.75
    && all->runman->Position.x <= all->monster->Position.x + 19 * 2.75))
    && (all->runman->Position.y + 312 * 0.65 >= all->monster->Position.y
    && all->runman->Position.y + 312 * 0.65 <=
    all->monster->Position.y + 42 * 2.75 + 15)) {
        all->score += 10;
        sfText_setString(all->scoretext->text, longtochar(all->score));
        all->monster->Position.x = 1948 + ((rand() % 10) * 100);
        sfSprite_setPosition(all->monster->Sprite, all->monster->Position);
        sfMusic_play(all->mobdeathsound);
    }
    sfClock_restart(all->clock);
}

void jeu_map_anime_monster(all *all)
{
    sfSprite_setTexture(all->monster->Sprite
    , all->monstertext[all->comptmonstre], sfTrue);
    all->comptmonstre++;
    all->Rect.top = 0;
    all->Rect.left = 65;
    all->Rect.width = -65;
    all->Rect.height = 42;
    sfSprite_setTextureRect(all->monster->Sprite, all->Rect);
    if (all->comptmonstre == 4) {
        all->comptmonstre = 0;
    }
    sfClock_restart(all->animmonster);
}

void jeu_map_gestion_player_anim_slash_or_run(all *all)
{
    if (all->slash == 0) {
        sfSprite_setTexture(all->runman->Sprite
        , all->runtext[all->compt], sfTrue);
        all->compt++;
        if (all->acitvesound != 0) {
            sfMusic_play(all->runsound);
            all->acitvesound = 0;
        }
        if (all->compt == 24)
            all->compt = 0;
    } else {
        sfSprite_setTexture(all->runman->Sprite
        , all->slashrun[all->compt], sfTrue);
        all->compt++;
        if (all->compt == 24) {
            all->compt = 0;
            all->slash = 0;
        }
    }
}

int hitbox_pillar_test_run(all *all)
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