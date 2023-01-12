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

int main(int ac, char **av)
{
    int counter_o = 0, counter_t = 0;
    if (error_gestion_arguments(ac, av) == 84)
        return 84;
    while (1) {
        if (signal_handling(&counter_o, &counter_t) == 1)
            return 0;
        sleep(1);
    }
    return 0;
}
