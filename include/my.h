/*
** EPITECH PROJECT, 2018
** ol
** File description:
** lol
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    typedef struct text_t
    {
        sfText *text;
        char *valeur;
        sfVector2f position;
    }     text;

    typedef struct color_t
    {
        sfColor degrade;
        int sensr;
        int sensb;
        int sensg;
        int sensa;
    }     colordegrade;

    typedef struct vitesse_t
    {
        float x;
        float y;
    }       speed_t;

    typedef struct game_object_t
    {
        int type;
        sfTexture *Texture;
        sfSprite *Sprite;
        sfVector2f Position;
        speed_t speed;
        sfIntRect Rect;
    }       game_object;

    typedef struct s_score
    {
        int rank;
        char *name;
        long long score;
        struct s_score *next;
    }       t_score;

    typedef struct colordegradsens_s
    {
        int sensr;
        int sensb;
        int sensg;
        int sensa;
    }       colordegradsens_t;

    typedef struct multi_object_t
    {
        game_object *object;
        int type;
        struct multi_object_t *next;
    }       multi_object;

    typedef struct menu_t
    {
        sfEvent event;
        sfRenderWindow *window;
        t_score *list;
        game_object *menu;
        sfFont *font;
        text *scorename;
        text *scoretext;
        sfColor color;
        colordegrade degrade;
    }       menu_s;

    typedef struct loose_t
    {
        sfEvent event;
        game_object *menu;
        game_object *entername;
        sfRenderWindow *window;
        t_score *list;
        t_score *backup;
        t_score *news;
        t_score *after;
        sfFont *font;
        text **scorename;
        char *buffer;
        text **scoretext;
        text *name;
        long long score;
        int pass;
        int count;
        int count2;
        char **map;
        int exit;
    }       loose_s;

    typedef struct all_t
    {
        float vitesse;
        int lol;
        int compt;
        int jump;
        int comptmonstre;
        int slash;
        int tomb;
        float scorefloat;
        long long score;
        float jumpforceinit;
        float jumpforce;
        float g;
        int timeinit;
        int timeanim;
        int pause;
        int acitvesound;
        int pointhaut;
        sfEvent event;
        sfTexture **jumptext;
        sfTexture **slashrun;
        sfVector2f scale;
        sfIntRect Rect;
        sfMusic *music;
        sfMusic *runsound;
        sfMusic *jumplandsound;
        sfMusic *slashsound;
        sfMusic *mobdeathsound;
        sfFont *font;
        text *scoretext;
        sfClock *clock;
        sfClock *anime;
        sfClock *animejump;
        sfClock *scoreclock;
        sfClock *animmonster;
        game_object *sky;
        game_object *veg;
        game_object *ground;
        game_object *skytwo;
        game_object *vegtwo;
        game_object *groundtwo;
        game_object *runman;
        game_object *scoreimage;
        game_object *pillar;
        game_object *monster;
        game_object *spike;
        game_object *pauseback;
        sfTexture **runtext;
        sfTexture **monstertext;
        multi_object *pillar_m;
        multi_object *save;
        sfTexture *pillartext;
        sfTexture *spiketext;
        game_object *pillarrun;
        sfRenderWindow *window;
        int countplacemap;
        int breakmap;
        char **map;
        int pass;
        double longeur_parcourue;
        int avance;
        int exit;
    }     all;

    menu_s *initmenu();
    void initmenu_2(menu_s *menuvar);
    int menuevent_2(menu_s *menuvar, char **map, sfRenderWindow *window);
    int menuevent(menu_s *menuvar, char **map);
    void affichage(menu_s *menuvar);
    void menu(char **map);
    sfColor degrade_color(colordegrade *coloradd
    , sfColor actuelle, sfText *text);
    sfColor create_color(int r, int b, int g, int a);
    sfColor degrade_color_haute(colordegrade *coloradd, sfColor actuelle);
    sfColor degrade_color_basse(colordegrade *coloradd, sfColor actuelle);
    colordegrade create_degrade(sfColor color, colordegradsens_t sens);
    colordegradsens_t create_sensdregrad(int sensr, int sensb, int sensg
    , int sensa);
    void loosescreen_5(loose_s *loosevar);
    void loosescreen_6(loose_s *loosevar);
    void loosescreen_7(loose_s *loosevar);
    void loosescreen_8(loose_s *loosevar);
    void loosescreen(sfRenderWindow *window, long long score, char **map);
    void loosescreen_3(loose_s *loosevar);
    void loosescreen_4(loose_s *loosevar);
    void loosescreen_5_1(loose_s *loosevar);
    void loosescreen_5_2(loose_s *loosevar);
    void loosescreen_5_3(loose_s *loosevar);
    char *prepare_buffer();
    loose_s *initloose(sfRenderWindow *window, long long score, char **map);
    void initloose_2(loose_s *loosevar);
    void save(t_score *list);
    char *longtocharspe(long long nblist);
    char *createarrayspe(char *nb);
    int my_strlen(char const *str);
    t_score *lecturescore();
    t_score *lecturescore_1(t_score *list);
    t_score *lecturescore_2(t_score *list, int fichier, int nb, int nbr2);
    void my_rev_list(t_score **begin);
    t_score **my_rev_list_1(int end, int mid, t_score **array);
    game_object *create_object(const char *path_to_spritesheet,
    sfVector2f pos, sfIntRect rect, speed_t speed);
    void destroy_texturearray(int nb, sfTexture **texture);
    void destroy_object(game_object *obj, int nb, sfTexture **texture);
    sfIntRect create_rect(int top, int left, int height, int width);
    sfVector2f create_vect(float x, float y);
    int calcultemp(int timeanim, float jump, float g, int nbimage);
    speed_t create_speed(float x, float y);
    char *longtochar(long long nblist);
    char *createarray(char *nb, int i);
    all *init1();
    int my_put_nbr(long long nb);
    void menu(char **map);
    sfRenderWindow *create_windows(int width, int height, int bit);
    game_object *move_objectx(game_object *obj, int startx, int endx, int spe);
    text *create_text(char *valeur, sfVector2f position, int police
    , sfFont *font);
    int readmap(char *filepath);
    int jeumap(sfRenderWindow *window, char **map);
    void destroy1(all* all);
    void desactmusic(all* all);
    void activemusic(all* all);
    int jeumap(sfRenderWindow *window, char **map);
    all *jeu_map_1(all *all);
    void jeu_map_score(all *all);
    void jeu_map_display(all *all);
    void jeu_map_gestion_player(all *all);
    void jeu_map_gestion_player_win(all *all);
    void jeu_map_gestion_player_jump(all *all);
    void jeu_map_anime_monster(all *all);
    void jeu_move_create_map_infini(all *all);
    void jeu_move(all *all);
    int create_list_objct(all *all, int i, multi_object **list
    , multi_object *element);
    sfRenderWindow *create_windows(int width, int height, int bit);
    all *create_list(char **map, all *all);
    void my_rev_listspe(multi_object **begin, int i);
    multi_object **my_rev_listspe_1(int end, int mid, multi_object **array);
    int readmap(char *filepath);
    int verifmap(char **map, int lenght);
    int verifmap_2(char **map, int count2, int count1, int endline);
    all *move_objectmassx(all* all);
    void activemusic(all* all);
    void desactmusic(all* all);
    int calcultemp(int timeanim, float jump, float g, int nbimage);
    char *createarray(char *nb, int i);
    text *create_text(char *valeur, sfVector2f position, int police
    , sfFont *font);
    void destroy1spe(all* all);
    void destroy1(all* all);
    void destroy2(all* all);
    all *init1();
    all *init2(all *everything);
    all *init2_1(all *everything);
    all *init3(all *everything);
    all *init3_1(all *everything);
    all *init4(all *everything);
    all *init4_1(all *everything);
    multi_object *create_list_2(all *all, char **map);
    void create_list_2_1(all *all, char **map, int *i,
    multi_object *list);
    multi_object *create_list_2_object_1(all *all, multi_object *list);
    multi_object *create_list_2_object_3(all *all, multi_object *list);
    multi_object *create_list_2_object_2(all *all, multi_object *list);
    all *jeumap_init_1(all *all);
    all *jeumap_init_2(all *all);
    all *jeumap_init_3(all *all);
    all *jeumap_init_4(all *all);
    all *jeumap_init_5(all *all);
    all *jeu_gestion_event(all * all);
    all *jeu_gestion_event_pause_2_1(all *all);
    void jeu_gestion_event_pause_2_2(all *all);
    all *jeu_gestion_event_close(all *all);
    void jeu_gestion_event_jump(all *all);
    void jeu_gestion_event_slash(all *all);
    void jeu_gestion_event_pause_1(all *all);
    void jeu_move_create_map_2(all *all);
    void jeu_move_create_map_1(all *all);
    void jeu_move_create_map(all *all);
    void jeu_move_create_map_3(all *all);
    void jeu_move_create_map_3_1(all *all);
    void jeu_move_create_map_infini(all *all);
    void jeu_move_object(all *all);
    int hitbox_pillar_recept_on_pillar(all *all);
    int hitbox_pillar_test_run(all *all);
    void jeu_map_gestion_player_death_pillar(all *all);
    void jeu_map_gestion_player_death_spike(all *all);
    void jeu_map_gestion_player_anim_slash_or_run(all *all);
    void jeu_map_gestion_player_recept_on_pillar(all *all);
    void jeu_map_gestion_player_run_on_pillar(all *all);
    void jeu_map_gestion_player_death_or_win_1(all *all);
    void jeu_map_gestion_player_death_or_win_2(all *all);
    void loosescreen(sfRenderWindow *window, long long score, char **map);
    text *create_text(char *valeur, sfVector2f position, int police
    , sfFont *font);
    game_object *move_objectx(game_object *obj, int startx, int endx, int spe);

#endif /* !MY_H_ */