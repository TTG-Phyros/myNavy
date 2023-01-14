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
    write(1, "file representing the positions of the ships.\n", 46);
}

int main(int ac, char **av)
{
    int client_pid, error = error_gestion_arguments(ac, av);
    if (error == 84)
        return 84;
    if (error == 1)
        return 0;
    if (ac == 2) {
        client_pid = binary_to_decimal(receive_pid(), 22);
        write(1, "\nenemy connected\n", 18);
        game(client_pid, av[1]);
    }
    if (ac == 3) {
        write(1, "\nsuccessfully connected\n", 25);
        game(str_to_int(av[1]), av[2]);
    }
    return client_pid = 0;
}
