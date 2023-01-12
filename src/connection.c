/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** connection
*/

#include "../include/navy.h"

int display_pid(void)
{
    int pid = getpid();
    char *str_pid = int_to_str(pid);
    write(1, "my_pid: ", 9);
    write(1, str_pid, my_strlen(str_pid));
    write(1, "\nwaiting for enemy connection...\n", 34);
    return pid;
}

void send_pid(int pid, char *str)
{
    int *binary_pid = decimal_to_binary(pid), host = str_to_int(str);
    for (int i = 0; i <= 22; i++) {
        usleep(100000);
        if (binary_pid[i] == 0) {
            printf("SIGUSR1 SENT\n");
            kill(host, SIGUSR1);
        }
        if (binary_pid[i] == 1) {
            printf("SIGUSR2 SENT\n");
            kill(host, SIGUSR2);
        }
    }
}
