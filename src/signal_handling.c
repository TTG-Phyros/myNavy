/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** signal_handling
*/

#include "../include/navy.h"

int GLOBAL_SIGNAL;

void pid_handler(int signo)
{
    if (signo == SIGUSR1)
        GLOBAL_SIGNAL = 4;
    if (signo == SIGUSR2)
        GLOBAL_SIGNAL = 5;
}

int *receive_pid(void)
{
    int received_value = 0, *pid = malloc (23 * sizeof(int));
    for (int i = 0; received_value != 23;) {
        signal(SIGUSR1, pid_handler);
        signal(SIGUSR2, pid_handler);
        if (GLOBAL_SIGNAL == 4) {
            pid[i] = 0;
            i++;
            GLOBAL_SIGNAL = 0;
            received_value++;
        }
        if (GLOBAL_SIGNAL == 5) {
            pid[i] = 1;
            i++;
            GLOBAL_SIGNAL = 0;
            received_value++;
        }
    }
    return pid;
}
