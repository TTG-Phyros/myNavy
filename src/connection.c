/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** connection
*/

#include "../include/navy.h"

char *visual_output(int choice, int pid, char **enemy_map)
{
    if (choice == 1) {
        write(1, "wrong position", 15);
        return send_data(pid, enemy_map);
    }
    if (choice == 2) {
        write(1, "case already bombed", 20);
        return send_data(pid, enemy_map);
    }
    return NULL;
}

char *send_data(int pid, char **enemy_map)
{
    char *buffer = NULL;
    ssize_t read_value = 0;
    size_t len = 0;
    write(1, "\nattack: ", 10);
    while ((read_value = getline(&buffer, &len, stdin)) != 3) {
        if (read_value != 3)
            write(1, "wrong position", 15);
        write(1, "\nattack: ", 10);
    }
    if (buffer[0] < 'A' || buffer[0] > 'H') {
        return visual_output(1, pid, enemy_map);
    } else if (buffer[1] < '1' || buffer[1] > '8')
        return visual_output(1, pid, enemy_map);
    if (enemy_map[buffer[1] - '1'][buffer[0] - 'A'] == 'x')
        return visual_output(2, pid, enemy_map);
    send_data_to_pid(decimal_to_binary(buffer[0], 7), pid, 7);
    send_data_to_pid(decimal_to_binary(buffer[1], 7), pid, 7);
    return buffer;
}

int display_pid(int ac)
{
    int pid = getpid();
    char *str_pid = int_to_str(pid);
    write(1, "my_pid: ", 9);
    write(1, str_pid, my_strlen(str_pid));
    write(1, "\n", 1);
    if (ac == 2)
        write(1, "waiting for enemy connection...\n", 33);
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
