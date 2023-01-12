/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** error_handling
*/

#include "../include/navy.h"

int error_gestion_file(char **map)
{
    for (int i = 0; map[i]; i++) {
        if (map[i][0] > '5' || map[i][0] < '2')
            return 84;
        if (map[i][1] != ':' || map[i][4] != ':')
            return 84;
        if (map[i][2] > 'H' || map[i][2] < 'A' ||
        map[i][5] > 'H' || map[i][5] < 'A')
            return 84;
        if (map[i][3] > '8' || map[i][3] < '1' ||
        map[i][6] > '8' || map[i][6] < '1')
            return 84;
        if (map[i][7] != '\n' && map[i][7] != '\0')
            return 84;
    }
    return 0;
}

int error_gestion_arguments(int ac, char **av)
{
    int index = 1;
    if (ac == 3)
        index = 2;
    if (ac > 3) {
        write(2, "Too many arguments.\n", 21);
        return 84;
    }
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2]) {
            flag_h();
            return 1;
        }
    char **map = file_to_array(av[index]);
    if (error_gestion_file(map) == 84) {
        write(2, "File not valid.\n", 17);
        return 84;
    }
    display_pid();
    return 0;
}
