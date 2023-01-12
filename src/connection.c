/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** connection
*/

#include "../include/navy.h"

void display_pid(void)
{
    char *pid = int_to_str(getpid());
    write(1, "my_pid: ", 9);
    write(1, pid, my_strlen(pid));
    write(1, "\nwaiting for enemy connection...\n", 34);
}
