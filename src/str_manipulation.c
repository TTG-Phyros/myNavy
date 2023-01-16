/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** str_manipulation
*/

#include "../include/navy.h"

char *my_revstr(char *str)
{
    int i = 0;
    char temp;
    for (; str[i]; i++);
    i--;
    for (int j = 0; j <= i / 2; j++, i--) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
    return str;
}

int str_to_int(char *str)
{
    int ac_num = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        if (str[i] >= '0' && str[i] <= '9' && ac_num > 0) {
            ac_num *= 10;
            ac_num += str[i] - '0';
        }
        if (str[i] >= '0' && str[i] <= '9' && ac_num == 0)
            ac_num = str[i] - '0';
    }
    return ac_num;
}

char *int_to_str(int nb)
{
    char *str = malloc((intlen(nb) + 1) * sizeof(char));
    if (nb == 0)
        str[0] = '0';
    int i = 0;
    for (; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    my_revstr(str);
    printf("%s\n", str);
    return str;
}

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i]; i++);
    return i;
}

char *space_str(char *str)
{
    char *ans = malloc(sizeof(char) * (my_strlen(str) + 1) * 2);
    for (int i = 0, j = 0; str[j]; i++) {
        if (i % 2 == 0)
            ans[i] = str[j++];
        else
            ans[i] = ' ';
    }
    return ans;
}
