/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <signal.h>
    #include <fcntl.h>
    #include <stdio.h>

    #define HELP "content/h_graphic"

    // * int_manipulation.c
    int intlen(int nb);
    int my_compute_power_it(int nb, int p);
    int *decimal_to_binary(int nb, int len);
    int binary_to_decimal(int *list_nb, int len);

    // * str_manipulation.c
    char *my_revstr(char *str);
    int str_to_int(char *str);
    char *int_to_str(int nb);
    int my_strlen(char *str);
    char *space_str(char *str);


    // * connection.c
    int display_pid(int ac);
    void send_pid(int pid, char *str, int len);
    void send_data_to_pid(int *bin_info, int pid, int len);
    void send_death(int pid);
    char *send_data(int pid);
    
    // * signal_handling.c
    void data_handler(int signo);
    int *receive_data(int len);

    // * file_gestion.c
    int compt_nb_lines(char *filepath);
    void my_strcat(char *dest, char *src);
    char **file_to_array(char *filepath);

    // * error_handling.c
    int error_gestion_arguments(int ac, char **av);

    // * main.c
    int main(int ac, char **av);
    int flag_h(void);

    // * game.c
    void game(int receiver_pid, char *filepath, int ac);
    int check_finished(char **map, int tour);

    // * map.c
    void display_map(char **my_map, char **enemy_map);
    char **create_empty_map(void);
    void i_love_c_one(char **map, char **coords, int i, int j);
    char **create_map_from_file(char *fp);

    // * cat.c
    int cat_help(char *str);
    int get_nbr_char(char const *filepath);

#endif
