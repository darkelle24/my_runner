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

multi_object *create_list_2_object_2(all *all, multi_object *list)
{
    multi_object *element = malloc(sizeof(multi_object));

    element->object = create_object(NULL,
    create_vect(all->countplacemap * 75, 745)
    , create_rect(0, 0, 75, 80), create_speed(all->veg->speed.x * 8, 0));
    sfSprite_setTexture(element->object->Sprite, all->spiketext, sfTrue);
    element->next = list;
    element->type = 2;
    list = element;
    return (list);
}

multi_object *create_list_2_object_3(all *all, multi_object *list)
{
    multi_object *element = malloc(sizeof(multi_object));

    element->object = create_object(NULL,
    create_vect(all->countplacemap * 75, 670)
    , create_rect(0, 0, 75, 150), create_speed(all->veg->speed.x * 8, 0));
    sfSprite_setTexture(element->object->Sprite, all->pillartext, sfTrue);
    element->next = list;
    element->type = 3;
    list = element;
    return (list);
}

multi_object *create_list_2(all *all, char **map)
{
    int i = 0;

    multi_object *list = NULL;
    while (all->countplacemap < 30 && map[4][all->countplacemap] != '\0'
    && all->breakmap == 0) {
        create_list_2_1(all, map, &i, list);
        all->countplacemap++;
    }
    my_rev_listspe(&list, i);
    return (list);
}

all *create_list(char **map, all *all)
{
    sfIntRect lol = create_rect(0, 0, 75, 150);
    multi_object *list = NULL;

    all->pillartext = sfTexture_createFromFile("ressource/pillar.png", &lol);
    lol = create_rect(0, 0, 75, 80);
    all->spiketext = sfTexture_createFromFile("ressource/spike2.png", &lol);
    all->breakmap = 0;
    all->countplacemap = 0;
    if (map != NULL)
        list = create_list_2(all, map);
    else
        all->countplacemap = 30;
    all->pillar_m = list;
    all->save = list;
    return (all);
}

all *jeumap_init_5(all *all)
{
    char filepathrunslash[45] = "ressource/Run Slashing/Run Slashing_000.png";

    all->slashrun = malloc(sizeof(sfTexture*) * 24);
    all->compt = 0;
    while (all->compt < 24) {
        filepathrunslash[37] = (all->compt / 10) + 48;
        filepathrunslash[38] = all->compt % 10 + 48;
        all->slashrun[all->compt] = sfTexture_createFromFile
        (filepathrunslash, NULL);
        all->compt++;
    }
    return (all);
}