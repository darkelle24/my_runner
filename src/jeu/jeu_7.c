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

all *jeumap_init_4(all *all)
{
    char filepathjump[35] = "ressource/Jumping/Jumping_000.png";

    all->jumptext = malloc(sizeof(sfTexture*) * 40);
    all->compt = 0;
    while (all->compt < 40) {
        filepathjump[27] = (all->compt / 10) + 48;
        filepathjump[28] = all->compt % 10 + 48;
        all->jumptext[all->compt] = sfTexture_createFromFile
        (filepathjump, NULL);
        all->compt++;
    }
    all = jeumap_init_5(all);
    return (all);
}

all *jeumap_init_3(all *all)
{
    all->monstertext = malloc(sizeof(sfTexture*) * 4);
    all->compt = 0;
    while (all->compt < 4) {
        all->Rect.left = 65 * all->compt;
        all->Rect.top = 0;
        all->Rect.width = 65;
        all->Rect.height = 42;
        all->monstertext[all->compt] = sfTexture_createFromFile
        ("ressource/montre.png", &all->Rect);
        all->compt++;
    }
    all = jeumap_init_4(all);
    return (all);
}

all *jeumap_init_2(all *all)
{
    char filepathrun[35] = "ressource/Running/Running_000.png";

    all->runtext = malloc(sizeof(sfTexture*) * 24);
    all->compt = 0;
    while (all->compt < 24) {
        filepathrun[27] = (all->compt / 10) + 48;
        filepathrun[28] = all->compt % 10 + 48;
        all->runtext[all->compt] = sfTexture_createFromFile
        (filepathrun, NULL);
        all->compt++;
    }
    all = jeumap_init_3(all);
    return (all);
}

all *jeumap_init_1(all *all)
{
    srand(time(NULL));
    sfMusic_setLoop(all->music, sfTrue);
    sfMusic_setVolume(all->music, 10);
    sfMusic_setLoop(all->runsound, sfTrue);
    sfMusic_setVolume(all->runsound, 100);
    sfMusic_setVolume(all->jumplandsound, 45);
    sfMusic_setVolume(all->slashsound, 40);
    sfMusic_setVolume(all->mobdeathsound, 20);
    all = jeumap_init_2(all);
    all->scale.x = 0.65;
    all->scale.y = 0.65;
    sfSprite_setScale(all->runman->Sprite, all->scale);
    all->scale.x = 2.75;
    all->scale.y = 2.75;
    sfSprite_setScale(all->monster->Sprite, all->scale);
    all->compt = 1;
    sfMusic_play(all->music);
    return (all);
}

all *jeu_gestion_event_close(all *all)
{
    if (all->event.type == sfEvtClosed) {
        sfRenderWindow_close(all->window);
        all->exit = 1;
    }
    return (all);
}