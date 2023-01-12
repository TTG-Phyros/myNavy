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

    //=============
    #include <stdio.h>
    //=============

    // * int_manipulation.c
    int intlen(int nb);
    int my_compute_power_it(int nb, int p);
    int *decimal_to_binary(int nb);

    // * str_manipulation.c
    char *my_revstr(char *str);
    int str_to_int(char *str);
    char *int_to_str(int nb);
    int my_strlen(char *str);


    // * connection.c
    int display_pid(void);
    void send_pid(int pid, char *str);

    // * signal_handling.c
    void sig_handler(int signo);
    int quit_handler(int counter_o, int counter_t);
    int signal_handling(int *counter_o, int *counter_t);

    // * file_gestion.c
    int compt_nb_lines(char *filepath);
    void my_strcat(char *dest, char *src);
    char **file_to_array(char *filepath);

    // * error_handling.c
    int error_gestion_arguments(int ac, char **av);

    // * main.c
    int main(int ac, char **av);
    void flag_h(void);

#endif
