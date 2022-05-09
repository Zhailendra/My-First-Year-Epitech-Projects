/*
** EPITECH PROJECT, 2021
** My_hunter
** File description:
** Program which make a video game based on the rules of Duck Hunt game
*/

#include "../include/my_hunter.h"

void game_start(window_t *my_window, target_t *my_target,
weapon_t *my_weapon)
{
    sfEvent event;

    sfRenderWindow_setFramerateLimit(my_window->window, 60);
    animation(my_window, my_target);
    set_weapon(my_window, my_weapon);
    set_score(my_window);
    display_game(my_window, my_target, my_weapon);
    while (sfRenderWindow_pollEvent(my_window->window, &event)) {
        analyse_events(my_window, my_target, my_weapon, event);
    }
}

void my_hunter(window_t *my_window, target_t *my_target,
weapon_t *my_weapon)
{
    sound_t *my_sound = malloc(sizeof(sound_t));
    sfVideoMode mode = {1920, 1080, 32};
    sprite_creation(my_window, my_target, my_weapon);
    my_window->window = sfRenderWindow_create(mode, "My_hunter",
    sfResize | sfClose, NULL);

    set_sound(my_window, my_sound);
    manage_value(my_target);
    my_window->hearths_rect = (sfIntRect) {0, 0, 190, 41};
    while (sfRenderWindow_isOpen(my_window->window)) {
        game_start(my_window, my_target, my_weapon);
    }
    sfSprite_destroy(my_target->target_sprite);
    sfSprite_destroy(my_target->rev_target_sprite);
    sfSprite_destroy(my_window->font_sprite);
    sfSound_destroy(my_sound->sound);
    sfSoundBuffer_destroy(my_sound->soundbuff);
    sfRenderWindow_destroy(my_window->window);
    my_printf("THANKS FOR PLAYING\n");
}

int manage_usage(char *usage)
{
    for (int i = 0; usage[i] != '\0'; i++) {
        if (usage[i] == '-' && usage[i + 1] == 'h') {
            my_printf("Usage\n    ./my_hunter\n\nDESCRIPTION\n\n   Click on ");
            my_printf("targets to earn points.\n   You have 4 lifes and you ");
            my_printf("lose a life if you miss 3 times your shot.\n\n");
            my_printf("If you press W and X keys you can unlock a cheat ");
            my_printf("which allows you to kill both targets without ");
            my_printf("aiming at them.\n\n");
            my_printf("Press ESC to exit game\n");
            my_printf("GOOD LUCK\n");
            return (0);
        } else {
            my_printf("Error\n");
            return (1);
        }
    }
}

void free_struct(window_t *my_window, target_t *my_target, weapon_t *my_weapon)
{
    free(my_window);
    free(my_target);
    free(my_weapon);
}

int main(int ac, char **av)
{
    window_t *my_window = malloc(sizeof(window_t));
    target_t *my_target = malloc(sizeof(target_t));
    weapon_t *my_weapon = malloc(sizeof(weapon_t));
    my_window->score = 0;
    my_window->chances = 3;
    my_window->life = 4;
    my_window->tmp = 0;

    if (ac != 1) {
        if (manage_usage(av[1]) == 1)
            return (84);
        else
            return (0);
    } else
        my_hunter(my_window, my_target, my_weapon);
    free_struct(my_window, my_target, my_weapon);
}
