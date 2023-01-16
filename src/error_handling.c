/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** error_handling
*/

#include "../include/navy.h"

int good_boat_check(char **map)
{
    for (int i = 0, good = 0; map[i]; i++, good = 0) {
        if (map[i][5] - map[i][2] == map[i][0] - '0' - 1)
            good++;
        if (map[i][6] - map[i][3] == map[i][0] - '0' - 1)
            good++;
        if (good != 1)
            return 84;
    }
    return 0;
}

int error_gestion_file(char **map)
{
    int *boats = malloc(sizeof(int) * 4);
    if (map == NULL) return 84;
    for (int i = 0; map[i]; i++) {
        if (map[i][0] > '5' || map[i][0] < '2')
            return 84;
        if (boats[map[i][0] - '0' - 2] == 1) return 84;
        else
            boats[map[i][0] - '0' - 2] = 1;
        if (map[i][1] != ':' || map[i][4] != ':')
            return 84;
        if (map[i][2] > 'H' || map[i][2] < 'A' ||
        map[i][5] > 'H' || map[i][5] < 'A')
            return 84;
        if (map[i][3] > '8' || map[i][3] < '1' ||
        map[i][6] > '8' || map[i][6] < '1')
            return 84;
        if (map[i][7] != '\n' && map[i][7] != '\0') return 84;
    }
    return good_boat_check(map);
}

int error_text_display(int choice)
{
    if (choice == 1) {
        write(2, "Too many arguments.\n", 21);
        return 84;
    }
    if (choice == 2) {
        write(2, "Not enought arguments.\n", 24);
        return 84;
    }
    if (choice == 3) {
        write(2, "File not valid.\n", 17);
        return 84;
    }
    if (choice == 4)
        return flag_h();
    if (choice == 5) {
        write(2, "Invalid PID.\n", 14);
        return 84;
    }
    return 0;
}

int check_if_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return -1;
    return 0;
}

int error_gestion_arguments(int ac, char **av)
{
    if (ac > 3)
        return error_text_display(1);
    if (ac < 2)
        return error_text_display(2);
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
            return error_text_display(4);
    if (ac == 3)
        if (check_if_number(av[1]) == -1)
            return error_text_display(5);
    int index = 1, pid = display_pid(ac);
    if (ac == 3) {
        send_pid(pid, av[1], 22);
        index = 2;
    }
    char **map = file_to_array(av[index]);
    if (error_gestion_file(map) == 84)
        return error_text_display(3);
    return 0;
}
