/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** main
*/

#include "../include/navy.h"

void flag_h(void)
{
    write(1, "USAGE\n    ./navy [first_player_pid] navy_positions\n", 52);
    write(1, "DESCRIPTION\n    first_player_pid: only for the 2nd player", 58);
    write(1, ". pid of the first player.\n    navy_positions:", 47);
    write(1, "file representing the positions of the ships.", 46);
}

int error_gestion_arguments(int ac, char **av)
{
    if (ac > 3) {
        write(2, "Too many arguments.\n", 21);
        return 84;
    }
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
            flag_h();
    return 0;
}

int main(int ac, char **av)
{
    if (error_gestion_arguments(ac, av) == 84)
        return 84;
    return 0;
}
