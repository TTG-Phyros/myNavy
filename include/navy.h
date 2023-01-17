/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    // * Includes
    #include <stdlib.h>
    #include <unistd.h>
    #include <signal.h>
    #include <fcntl.h>
    #include <stdio.h>

    // ? MACROS
    #define HELP "content/h_graphic"

    // ! FUNCTIONS
        // * cat.c
        int get_nbr_char(char const *filepath);
        int cat_help(char *str);
        void display_bombed(int letter, int number, int choice);

        // * connection.c
        char *send_data(int pid);
        int display_pid(int ac);
        void send_pid(int pid, char *str, int len);
        void send_data_to_pid(int *bin_info, int pid, int len);

        // * error_handling.c
        int good_boat_check(char **map);
        int check_file(char **map);
        int error_gestion_file(char **map);
        int error_text_display(int choice);
        int error_gestion_arguments(int ac, char **av);

        // * file_gestion.c
        int compt_nb_lines(char *filepath);
        void my_strcat(char *dest, char *src);
        char **file_to_array(char *filepath);

        // * game.c
        int game(int receiver_pid, char *filepath, int ac);
        int check_finished_enemy(char **enemy_map, int tour);
        int check_finished(char **map, int tour, char **enemy_map);
        void update_enemy_map(char **enemy_map, int bombed, char *case_bombed);
        int update_my_map(char **my_map, int *played_move,
                        int receiver_pid, int *tour);

        // * int_manipulation.c
        int intlen(int nb);
        int *decimal_to_binary(int nb, int len);
        int binary_to_decimal(int *list_nb, int len);
        int check_if_number(char *str);

        // * main.c
        int main(int ac, char **av);
        int flag_h(void);

        // * map.c
        void display_map(char **my_map, char **enemy_map);
        char **create_empty_map(void);
        int i_love_c_one(char **map, char **coords, int i, int j);
        char **create_map_from_file(char *fp);
        void c_one_is_my_bff(int ac, char **my_map,
                            char **enemy_map, int choice);

        // * signal_handling.c
        void data_handler(int signo);
        int *receive_data(int len);
        int lose(int choice, char **my_map, char **enemy_map);

        // * str_manipulation.c
        char *my_revstr(char *str);
        int str_to_int(char *str);
        char *int_to_str(int nb);
        int my_strlen(char *str);
        char *space_str(char *str);

#endif
