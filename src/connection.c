/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** connection
*/

#include "../include/navy.h"

char *send_data(int pid)
{
    char *buffer = malloc(sizeof(char) * 3);
    int read_value = 0;
    write(1, "\nattack: ", 10);
    while ((read_value = read(1, buffer, 2)) != 2)
        ;
    if (buffer[0] < 'A' || buffer[0] > 'H') {
        write(1, "\nwrong position", 16);
        return send_data(pid);
    }
    if (buffer[1] < '1' || buffer[1] > '8') {
        write(1, "\nwrong position", 16);
        return send_data(pid);
    }
    send_data_to_pid(decimal_to_binary(buffer[0], 7), pid, 8);
    send_data_to_pid(decimal_to_binary(buffer[1], 7), pid, 8);
    return buffer;
}

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

void send_death(int pid)
{
    for (int i = 0; i <= 16; i++) {
        usleep(10000);
        kill(pid, SIGUSR1);
    }
}
