/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu.c
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

void initmenu_2(menu_s *menuvar)
{
    sfRenderWindow_setFramerateLimit(menuvar->window, FRAMERET);
    sfRenderWindow_setVerticalSyncEnabled(menuvar->window, sfTrue);
    if (menuvar->list->score != 0 && menuvar->list->name[0] != ' ') {
        menuvar->scorename = create_text(menuvar->list->name
        , create_vect(670, 840), 40, menuvar->font);
        menuvar->scoretext = create_text(longtochar(menuvar->list->score)
        , create_vect(1100, 840), 40, menuvar->font);
        sfText_setColor(menuvar->scorename->text, menuvar->color);
        sfText_setColor(menuvar->scoretext->text, menuvar->color);
    } else {
        menuvar->scorename = create_text("No score", create_vect(860, 840)
        , 50, menuvar->font);
        sfText_setColor(menuvar->scorename->text, menuvar->color);
    }
}

int menuevent_2(menu_s *menuvar, char **map, sfRenderWindow *window)
{
    if (menuvar->event.mouseButton.x >= 683 &&
    menuvar->event.mouseButton.x <= 683 + 594
    && menuvar->event.mouseButton.y >= 417 &&
    menuvar->event.mouseButton.y <= 417 + 62) {
        destroy_object(menuvar->menu, 1, NULL);
        if (map != NULL) {
            jeumap(window, map);
            sfRenderWindow_close(window);
            return (1);
        } else {
            jeumap(window, NULL);
            sfRenderWindow_close(window);
            return (1);
        }
    }
    return (0);
}

int menuevent(menu_s *menuvar, char **map)
{
    while (sfRenderWindow_pollEvent(menuvar->window, &menuvar->event)) {
        if (menuvar->event.type == sfEvtClosed)
            sfRenderWindow_close(menuvar->window);
        if (menuvar->event.type == sfEvtMouseButtonReleased &&
        menuvar->event.mouseButton.button == sfMouseLeft) {
            if (menuevent_2(menuvar, map, menuvar->window) == 1)
                return (1);
            if (menuvar->event.mouseButton.x >= 683
            && menuvar->event.mouseButton.x <= 683 + 594
            && menuvar->event.mouseButton.y >= 651
            && menuvar->event.mouseButton.y <= 651 + 62) {
                sfRenderWindow_close(menuvar->window);
            }
        }
    }
    return (0);
}

void affichage(menu_s *menuvar)
{
    if (menuvar->list->score != 0 && menuvar->list->name[0] != ' ') {
        sfText_setColor(menuvar->scoretext->text
        , sfText_getColor(menuvar->scorename->text));
        sfRenderWindow_drawText(menuvar->window
        , menuvar->scoretext->text, NULL);
    }
}

void menu(char **map)
{
    menu_s *menuvar = initmenu();

    initmenu_2(menuvar);
    while (sfRenderWindow_isOpen(menuvar->window)) {
        if (menuevent(menuvar, map) == 0) {
            sfRenderWindow_drawSprite(menuvar->window
            , menuvar->menu->Sprite, NULL);
            menuvar->color = degrade_color(&menuvar->degrade
            , menuvar->color, menuvar->scorename->text);
            sfRenderWindow_drawText(menuvar->window
            , menuvar->scorename->text, NULL);
            affichage(menuvar);
            sfRenderWindow_display(menuvar->window);
        }
    }
    sfRenderWindow_destroy(menuvar->window);
}