/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** signal_handling
*/

#include "../include/navy.h"

int GLOBAL_SIGNAL;

void data_handler(int signo)
{
    if (signo == SIGUSR1)
        GLOBAL_SIGNAL = 4;
    if (signo == SIGUSR2)
        GLOBAL_SIGNAL = 5;
}

int *receive_data(int len)
{
    int *pid = malloc(len * sizeof(int));
    for (int i = 0; i != len;) {
        signal(SIGUSR1, data_handler);
        signal(SIGUSR2, data_handler);
        if (GLOBAL_SIGNAL == 4) {
            pid[i] = 0;
            i++;
            GLOBAL_SIGNAL = 0;
        }
        if (GLOBAL_SIGNAL == 5) {
            pid[i] = 1;
            i++;
            GLOBAL_SIGNAL = 0;
        }
    }
    return pid;
}

int lose(int choice, char **my_map, char **enemy_map)
{
    if (choice == 1) {
        display_map(my_map, enemy_map);
        write(1, "\nEnemy won\n\n", 13);
        return 1;
    }
    if (choice == 2) {
        display_map(my_map, enemy_map);
        write(1, "\nI won\n\n", 9);
    }
    return 0;
}
