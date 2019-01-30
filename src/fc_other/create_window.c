/*
** EPITECH PROJECT, 2019
** create_window.c
** File description:
** create_window.c
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

sfRenderWindow *create_windows(int width, int height, int bit)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bit;
    window = sfRenderWindow_create
    (video_mode, "My_Runner", sfDefaultStyle, NULL);
    return (window);
}
