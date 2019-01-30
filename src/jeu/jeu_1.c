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
#include "../../include/macro.h"

void jeu_map_display(all *all)
{
    sfRenderWindow_drawSprite(all->window, all->skytwo->Sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->sky->Sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->vegtwo->Sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->veg->Sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->runman->Sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->monster->Sprite, NULL);
    all->pillar_m = all->save;
    while (all->pillar_m != NULL && all->pillar_m->object->Position.x <= 2000) {
        sfRenderWindow_drawSprite(all->window
        , all->pillar_m->object->Sprite, NULL);
        all->pillar_m = all->pillar_m->next;
    }
    sfRenderWindow_drawSprite(all->window, all->groundtwo->Sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->ground->Sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->scoreimage->Sprite, NULL);
    sfRenderWindow_drawText(all->window, all->scoretext->text, NULL);
    if (all->pause == 1)
        sfRenderWindow_drawSprite(all->window, all->pauseback->Sprite, NULL);
    sfRenderWindow_display(all->window);
}

void jeu_map_score(all *all)
{
    if (sfClock_getElapsedTime(all->scoreclock).microseconds >= 1000000
    && all->pause == 0) {
        all->score++;
        all->timeinit = 15000;
        sfText_setString(all->scoretext->text, longtochar(all->score));
        sfClock_restart(all->scoreclock);
    }
}

void jeu_map_gestion_jump(all *all)
{
    sfSprite_setTexture(all->runman->Sprite
    , all->jumptext[all->compt], sfTrue);
    if (all->compt < 40)
        all->compt++;
    sfClock_restart(all->animejump);
}

all *jeu_map_1(all *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event) && all->exit == 0)
        all = jeu_gestion_event(all);
    if (all->exit == 1)
        return (all);
    if (sfClock_getElapsedTime(all->clock).microseconds >= 16666
    && all->pause == 0)
        jeu_move(all);
    if (sfClock_getElapsedTime(all->animmonster).microseconds >= 36666
    && all->pause == 0)
        jeu_map_anime_monster(all);
    if (sfClock_getElapsedTime(all->anime).microseconds >= all->timeanim
    && all->pause == 0)
        jeu_map_gestion_player(all);
    if (sfClock_getElapsedTime(all->animejump).microseconds >= all->pointhaut
    && all->jump != 0 && all->pause == 0)
        jeu_map_gestion_jump(all);
    jeu_map_score(all);
    jeu_map_display(all);
    return (all);
}

int jeumap(sfRenderWindow *window, char **map)
{
    all *all = init1();

    all->window = window;
    sfRenderWindow_setFramerateLimit(window, FRAMERET);
    all = create_list(map, all);
    all->map = map;
    all = jeumap_init_1(all);
    while (sfRenderWindow_isOpen(window) && all->pass == 0) {
        all = jeu_map_1(all);
    }
    destroy1spe(all);
    if (all->exit == 0)
        loosescreen(all->window, all->score, all->map);
    return (0);
}