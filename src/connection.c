/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** connection
*/

#include "../include/navy.h"

int display_pid(int ac)
{
    int pid = getpid();
    char *str_pid = int_to_str(pid);
    write(1, "my_pid: ", 9);
    write(1, str_pid, my_strlen(str_pid));
    if (ac == 2)
        write(1, "\nwaiting for enemy connection...\n", 34);
    return pid;
}

void send_pid(int info, char *pid, int len)
{
    int *binary_pid = decimal_to_binary(info, len), host = str_to_int(pid);
    for (int i = 0; i <= len; i++) {
        usleep(10000);
        if (binary_pid[i] == 0) {
            kill(host, SIGUSR1);
        }
        if (binary_pid[i] == 1) {
            kill(host, SIGUSR2);
        }
    }
}

void send_data_to_pid(int *bin_info, int pid, int len)
{
    for (int i = 0; i <= len; i++) {
        usleep(10000);
        if (bin_info[i] == 0) {
            kill(pid, SIGUSR1);
        }
        if (bin_info[i] == 1) {
            kill(pid, SIGUSR2);
        }
    }
}
