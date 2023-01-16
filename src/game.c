/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** game
*/

#include "../include/navy.h"

void display_map(char **my_map, char **enemy_map)
{
    write(1, "\nmy positions:\n", 16);
    write(1, " |A B C D E F G H\n", 19);
    write(1, "-+---------------\n", 19);
    for (int i = 1; i <= 8; i++) {
        write(1, int_to_str(i), 1);
        write(1, "|", 1);
        write(1, space_str(my_map[i]), my_strlen(my_map[i]) * 2);
        write(1, "\n", 1);
    }
    write(1, "\nenemy's positions:\n", 21);
    write(1, " |A B C D E F G H\n", 19);
    write(1, "-+---------------\n", 19);
    for (int i = 1; i <= 8; i++) {
        write(1, int_to_str(i), 1);
        write(1, "|", 1);
        write(1, space_str(enemy_map[i]), my_strlen(enemy_map[i]) * 2);
        write(1, "\n", 1);
    }
}

char *send_data(int pid)
{
    char *buffer = malloc(sizeof(char) * 3);
    int read_value = 0;
    write(1, "\nattack: ", 10);
    while ((read_value = read(1, buffer, 2)) != 2) {
        if (buffer[0] < 'A' || buffer[0] > 'H') {
            write(1, "\nwrong position", 16);
            return send_data(pid);
        }
        if (buffer[1] < '0' || buffer[1] > '9') {
            write(1, "\nwrong position", 16);
            return send_data(pid);
        }
    }
    send_pid(str_to_int(&buffer[0]), int_to_str(pid), 8);
    send_pid(str_to_int(&buffer[1]), int_to_str(pid), 8);
    return buffer;
}

void update_enemy_map(char **enemy_map, int bombed, char *case_bombed)
{
    int letter = case_bombed[0] - 'A' - 1, number = case_bombed[1] - '0';
    if (bombed == 1) {
        write(1, &case_bombed[0], 1);
        write(1, &case_bombed[1], 1);
        write(1, ": hit\n", 6);
        enemy_map[letter][number] = 'x';
    }
    if (bombed == 0) {
        write(1, &case_bombed[0], 1);
        write(1, &case_bombed[1], 1);
        write(1, ": missed\n", 10);
        enemy_map[letter][number] = 'o';
    }
}

int update_my_map(char **my_map, int *played_move, int receiver_pid)
{
    int letter = binary_to_decimal(played_move, 8);
    int number = binary_to_decimal(played_move + 8, 8);
    if (my_map[letter][number] >= '2' && my_map[letter][number] <= '5') {
        my_map[letter][number] = 'x';
        return kill(receiver_pid, SIGUSR1);
    }
    if (my_map[letter][number] == 'x') {
        my_map[letter][number] = 'x';
        return kill(receiver_pid, SIGUSR1);
    }
    my_map[letter][number] = 'o';
    return kill(receiver_pid, SIGUSR2);
}

void game(int receiver_pid, char *filepath, int ac)
{
    char **my_map = create_map_from_file(filepath);
    char **enemy_map = create_empty_map(), *case_bombed;
    display_map(my_map, enemy_map);
    int tour = ac - 2, *played_move;
    while (tour != -1) {
        if (tour == 0) {
            case_bombed = send_data(receiver_pid);
            played_move = receive_data(1);
            update_enemy_map(enemy_map, played_move[0], case_bombed);
        }
        if (tour == 1) {
            write (1, "\nwaiting for enemy's attack...", 31);
            played_move = receive_data(16);
            update_my_map(my_map, played_move, receiver_pid);
        }
        tour = !tour;
    }
}
