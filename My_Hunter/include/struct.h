/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-shailendra.blondel
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct {
    sfRenderWindow *window;
    sfTexture* font;
    sfSprite* font_sprite;
    sfTexture* score_font;
    sfSprite* score_sprite;
    sfTexture* hearths;
    sfSprite* hearths_sprite;
    sfIntRect hearths_rect;
    sfText* my_score;
    sfFont* background;
    sfText* s;
    sfClock *timer;
    int tmp;
    int chances;
    int score;
    int life;
}window_t;

typedef struct {
    sfTexture* target;
    sfSprite* target_sprite;
    sfVector2f target_position;
    sfTexture* rev_target;
    sfSprite* rev_target_sprite;
    sfVector2f rev_target_position;
    sfIntRect rect;
    sfIntRect rev_rect;
    sfClock *clock;
    sfTime time;
    float velocity;
}target_t;

typedef struct {
    sfTexture* weapon;
    sfSprite* weapon_sprite;
    sfVector2f weapon_position;
}weapon_t;

typedef struct {
    sfSound *sound;
    sfSoundBuffer *soundbuff;
}sound_t;

#endif
