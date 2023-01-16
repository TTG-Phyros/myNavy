/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** opens and displays graphic help file
*/
#include "../include/navy.h"

int get_nbr_char(char const *filepath)
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int nb_char = 0;
    stream = fopen(filepath, "r");
    while ((nread = getline(&line, &len, stream)) != -1)
        nb_char += nread;
    free(line);
    fclose(stream);
    return (nb_char);
}

int cat_help(char *str)
{
    int size = get_nbr_char(str);
    char buff[size];
    int to_op;
    to_op = open(str, O_RDONLY);
    if (to_op == -1){
        write (1, "Error with opening", 18);
        return (84);
    }
    size = read(to_op, buff, size);
    write (1, buff, size);
    return (0);
}