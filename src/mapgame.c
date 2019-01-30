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
#include "../include/my.h"
#include "../include/macro.h"

void jeu_move_create_map_infini(all *all)
{
    int random = (rand() % 100);

    if (random >= PILLARINF && random < SPIKEINF) {
        jeu_move_create_map_3(all);
    } else if (random >= SPIKEINF) {
        jeu_move_create_map_2(all);
    } 
}

void create_list_2_1(all *all, char **map, int *i, 
multi_object *list)
{
    if (map[9][all->countplacemap] == '3') {
            list = create_list_2_object_3(all, list);
            i++;
        }
        if (map[9][all->countplacemap] == '2') {
            list = create_list_2_object_2(all, list);
            i++;
        }
        if (map[9][all->countplacemap] == '1') {
            list = create_list_2_object_1(all, list);
            i++;
    }
}

void affiche()
{
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-') {
            if (av[1][1] == 'h')
                affiche();
            else if (av[1][1] == 'i')
                menu(NULL);
            else
                return (84);
        } else
            return (readmap(av[1]));
    } else
        return (84);
    return (0);
}