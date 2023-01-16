/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** map
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
        write(1, space_str(my_map[i - 1]), my_strlen(my_map[i - 1]) * 2);
        write(1, "\n", 1);
    }
    write(1, "\nenemy's positions:\n", 21);
    write(1, " |A B C D E F G H\n", 19);
    write(1, "-+---------------\n", 19);
    for (int i = 1; i <= 8; i++) {
        write(1, int_to_str(i), 1);
        write(1, "|", 1);
        write(1, space_str(enemy_map[i - 1]), my_strlen(enemy_map[i - 1]) * 2);
        write(1, "\n", 1);
    }
}

char **create_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    return map;
}

void i_love_c_one(char **map, char **coords, int i, int j)
{
    if (coords[i][5] - coords[i][2] != 0)
        map[coords[i][3] - '0' - 1][coords[i][2] - 'A' + j] = coords[i][0];
    if (coords[i][6] - coords[i][3] != 0)
        map[coords[i][3] - '0' + j - 1][coords[i][2] - 'A'] = coords[i][0];
}

char **create_map_from_file(char *fp)
{
    char **coords = file_to_array(fp), **map = create_empty_map();
    for (int i = 0; coords[i]; i++)
        for (int j = 0; j < coords[i][0] - '0'; j++)
            i_love_c_one(map, coords, i, j);
    return map;
}
