/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** file_gestion
*/

#include "../include/navy.h"

int compt_nb_lines(char *filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int compt = 0;
    fp = fopen(filepath, "r");
    if (!fp)
        return -1;
    while ((read = getline(&line, &len, fp)) != -1)
        compt++;
    return compt;
}

void my_strcat(char *dest, char *src)
{
    int i = 0;
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

char **file_to_array(char *filepath)
{
    int nb_lines = compt_nb_lines(filepath);
    if (nb_lines == -1)
        return NULL;
    char *line = NULL, **map = malloc((nb_lines + 1) * sizeof(char));
    FILE *fp = fopen(filepath, "r");
    if (!fp)
        return NULL;
    size_t len = 0;
    ssize_t read;
    for (int point = 0; (read = getline(&line, &len, fp)) != -1; point++) {
        map[point] = malloc((read + 1) * sizeof(char));
        my_strcat(map[point], line);
    }
    return map;
}
