/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** game
*/

#include "../include/navy.h"

int check_finished(char **map, int tour)
{
    int i = 0, y = 0;
    while (map[i]) {
        if (map[i][y] >= '2' || map[i][y] <= '5') {
            return !tour;
        }
        if (map[i][y] == '\0') {
            i++, y = 0;
        }
        y++;
    }
    return -1;
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

void display_bombed(int letter, int number, int choice)
{
    char lett = letter, numb = number;
    write(1, &lett, 1);
    write(1, &numb, 1);
    if (choice == 1)
        write(1, ": hit\n", 6);
    if (choice == 2)
        write(1, ": missed\n", 10);
}

int update_my_map(char **my_map, int *played_move, int receiver_pid, int *tour)
{
    int letter = binary_to_decimal(played_move, 7) - 'A';
    int *numbers = malloc(sizeof(int) * 8);
    for (int i = 0; i < 8; i++)
        numbers[i] = played_move[8 + i];
    int number = binary_to_decimal(numbers, 7) - '1';
    if (number <= 0) number = 0;
    if (letter <= 0) letter = 0;
    if (number == 255 - '1') return (*tour = -1);
    if (my_map[number][letter] >= '2' && my_map[number][letter] <= '5') {
        display_bombed(letter + 'A', number + '1', 1);
        my_map[number][letter] = 'x';
        return kill(receiver_pid, SIGUSR1);
    }
    if (my_map[number][letter] == 'x') {
        my_map[number][letter] = 'x';
        return kill(receiver_pid, SIGUSR1);
    }
    display_bombed(letter + 'A', number + '1', 2);
    my_map[number][letter] = 'o';
    return kill(receiver_pid, SIGUSR2);
}

int game(int receiver_pid, char *filepath, int ac)
{
    char **my_map = create_map_from_file(filepath);
    if (my_map == NULL) return error_text_display(3);
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
            update_my_map(my_map, played_move, receiver_pid, &tour);
        }
        tour = check_finished(my_map, tour);
    }
    return send_death(receiver_pid);
}
