/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** game
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

void update_enemy_map(char **enemy_map, int bombed, char *case_bombed)
{
    int letter = case_bombed[0] - 'A', number = case_bombed[1] - '0' - 1;
    if (bombed == 0) {
        write(1, &case_bombed[0], 1);
        write(1, &case_bombed[1], 1);
        write(1, ": hit\n", 6);
        enemy_map[number][letter] = 'x';
    }
    if (bombed == 1) {
        write(1, &case_bombed[0], 1);
        write(1, &case_bombed[1], 1);
        write(1, ": missed\n", 10);
        enemy_map[number][letter] = 'o';
    }
}

int update_my_map(char **my_map, int *played_move, int receiver_pid)
{
    int letter = binary_to_decimal(played_move, 7) - 'A';
    int *numbers = malloc(sizeof(int) * 8);
    for (int i = 0; i <= 8; i++)
        numbers[i] = played_move[8 + i];
    int number = binary_to_decimal(numbers, 8) - '0' - 1;
    if (number <= 0)
        number = 0;
    if (letter <= 0)
        letter = 0;
    if (my_map[number][letter] >= '2' && my_map[number][letter] <= '5') {
        my_map[number][letter] = 'x';
        return kill(receiver_pid, SIGUSR1);
    }
    if (my_map[number][letter] == 'x') {
        my_map[number][letter] = 'x';
        return kill(receiver_pid, SIGUSR1);
    }
    my_map[number][letter] = 'o';
    return kill(receiver_pid, SIGUSR2);
}

void c_one_is_my_bff(int ac, char **my_map, char **enemy_map, int choice)
{
    if (ac == choice + 1)
            display_map(my_map, enemy_map);
}

void game(int receiver_pid, char *filepath, int ac)
{
    char **my_map = create_map_from_file(filepath);
    char **enemy_map = create_empty_map(), *case_bombed;
    int tour = ac - 2, *played_move;
    while (tour != -1) {
        if (tour == 0) {
            c_one_is_my_bff(ac, my_map, enemy_map, 1);
            case_bombed = send_data(receiver_pid);
            played_move = receive_data(1);
            update_enemy_map(enemy_map, played_move[0], case_bombed);
        }
        if (tour == 1) {
            c_one_is_my_bff(ac, my_map, enemy_map, 2);
            write(1, "\nwaiting for enemy's attack...\n", 31);
            played_move = receive_data(16);
            update_my_map(my_map, played_move, receiver_pid);
        }
        tour = !tour;
    }
}
