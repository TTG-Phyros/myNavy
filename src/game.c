/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** game
*/

#include "../include/navy.h"

void display_map(char **my_map, char **enemy_map)
{
    write(1, "\nmy positions:\n", 16);
    write(1, " |A B C D E F G H\n", 19);
    write(1, "-+---------------\n", 19);
    for (int i = 1; i <= 8; i++) {
        write(1, int_to_str(i), 1);
        write(1, "|", 1);
        write(1, space_str(my_map[i]), my_strlen(my_map[i]) * 2);
        write(1, "\n", 1);
    }
    write(1, "\nenemy's positions:\n", 21);
    write(1, " |A B C D E F G H\n", 19);
    write(1, "-+---------------\n", 19);
    for (int i = 1; i <= 8; i++) {
        write(1, int_to_str(i), 1);
        write(1, "|", 1);
        write(1, space_str(enemy_map[i]), my_strlen(enemy_map[i]) * 2);
        write(1, "\n", 1);
    }
}

void game(int receiver_pid, char *filepath)
{
    char **my_map = create_map_from_file(filepath);
    char **enemy_map = create_empty_map();
    display_map(my_map, enemy_map);
    return;
}
