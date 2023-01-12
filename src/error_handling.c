/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** error_handling
*/

#include "../include/navy.h"

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
    printf("map[0]%s\n", map[0]);
    display_pid();
    return 0;
}
