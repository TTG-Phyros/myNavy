/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** signal_handling
*/

#include "../include/navy.h"

int GLOBAL_SIGNAL;

void sig_handler(int signo)
{
    if (signo == SIGUSR1) {
        write(1, "USR1 signal\n", 13);
        GLOBAL_SIGNAL = 1;
    }
    if (signo == SIGUSR2) {
        write(1, "USR2 signal\n", 13);
        GLOBAL_SIGNAL = 2;
    }
    if (signo == SIGQUIT) {
        write(1, "QUIT signal\n", 13);
        GLOBAL_SIGNAL = 3;
    }
}

int quit_handler(int counter_o, int counter_t)
{
    write(1, "Signal USR 1 : ", 16);
    write(1, int_to_str(counter_o), intlen(counter_o));
    write(1, "\nSignal USR 2 : ", 17);
    write(1, int_to_str(counter_t), intlen(counter_t));
    write(1, "\n", 1);
    return 1;
}

int signal_handling(int *counter_o, int *counter_t)
{
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    signal(SIGQUIT, sig_handler);
    if (GLOBAL_SIGNAL == 1) {
        *counter_o = *counter_o + 1;
        GLOBAL_SIGNAL = 0;
    }
    if (GLOBAL_SIGNAL == 2) {
        *counter_t = *counter_t + 1;
        GLOBAL_SIGNAL = 0;
    }
    if (GLOBAL_SIGNAL == 3)
        return quit_handler(*counter_o, *counter_t);
    return 0;
}
