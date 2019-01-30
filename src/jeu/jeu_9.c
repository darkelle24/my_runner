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

all *move_objectmassx(all* all)
{
    multi_object *freeobject;

    all->pillar_m = all->save;
    while (all->pillar_m != NULL) {
        all->pillar_m->object->Position.x += all->pillar_m->object->speed.x;
        if (all->pillar_m->object->Position.x <= -75) {
            freeobject = all->save;
            all->save = all->save->next;
            sfSprite_destroy(freeobject->object->Sprite);
            free(freeobject);
        } else
            sfSprite_setPosition(all->pillar_m->object->Sprite
            , all->pillar_m->object->Position);
        all->pillar_m = all->pillar_m->next;
    }
    all->pillar_m = all->save;
    return (all);
}

int verifmap_2(char **map, int count2, int count1, int endline)
{
    while (count2 < 11) {
        if (count2 == 10 && map[count2][count1] != '4') {
            return (-1);
        } else if (count2 != 10) {
            if (map[count2][count1] == '3' && map[count2 + 1][count1] == '3') {
                count2++;
            } else if (map[count2][count1] == '3'
            && map[count2 + 1][count1] != '3'){
                return (-1);
            } else {
                if (map[count2][count1] != '2' && map[count2][count1] != '1'
                && map[count2][count1] != ' ' && map[count2][count1] != '3')
                    return (-1);
                if (map[count2][count1] == '1')
                    endline++;
            }
        }
        count2++;
    }
    return (endline);
}

int verifmap(char **map, int lenght)
{
    int count1 = 0;
    int endline = 0;

    while (count1 < lenght - 1) {
        endline = verifmap_2(map, 0, count1, endline);
        if (endline == -1)
            return (84);
        count1++;
    }
    if (endline != 1)
        return (84);
    else
        return (0);
}

int readmap(char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char **map = malloc(sizeof(char *) * 11);
    int count = 1;
    int lenght = 0;
    int lenght2 = 0;
    size_t len = 0;

    if (fp == NULL)
        return (84);
    lenght2 = getline(&map[0], &len, fp);
    while (count < 11) {
        lenght = getline(&map[count], &len, fp);
        if (lenght == -1 || lenght != lenght2)
            return (84);
        count++;
    }
    if (verifmap(map, lenght) == 84)
        return (84);
    else
        menu(map);
    return (0);
}

multi_object *create_list_2_object_1(all *all, multi_object *list)
{
    multi_object *element = malloc(sizeof(multi_object));

    element->object = create_object("ressource/endflag.png",
    create_vect(all->countplacemap * 75, 620)
    , create_rect(0, 0, 200, 200), create_speed(all->veg->speed.x * 8, 0));
    element->next = list;
    element->type = 1;
    list = element;
    all->breakmap = 1;
    return (list);
}