/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** main
*/

#include "../include/navy.h"

int flag_h(void)
{
    write(1, "USAGE\n    ./navy [first_player_pid] navy_positions\n", 52);
    write(1, "DESCRIPTION\n    first_player_pid: only for the 2nd player", 58);
    write(1, ". pid of the first player.\n    navy_positions:", 47);
    write(1, "file representing the positions of the ships.\n", 46);
    return 1;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'H')
        return cat_help(HELP);
    int client_pid, error = error_gestion_arguments(ac, av), r_value = 0;
    if (error == 84)
        return 84;
    if (error == 1)
        return 0;
    if (ac == 2) {
        client_pid = binary_to_decimal(receive_data(23), 22);
        kill(client_pid, SIGUSR1);
        write(1, "\nenemy connected\n", 18);
        r_value = game(client_pid, av[1], ac);
    }
    if (ac == 3) {
        receive_data(1);
        write(1, "successfully connected\n", 24);
        r_value = game(str_to_int(av[1]), av[2], ac);
    }
    return r_value;
}
