/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** void_manipulation
*/

#include "../include/navy.h"

int intlen(int nb)
{
    int i = 1;
    for (; nb > 0; i++)
        nb /= 10;
    return i;
}

int *decimal_to_binary(int nb)
{
    int *ans = malloc(sizeof(int) * 23);
    for (int i = 22, j = 0; i >= 0; i--, j++) {
        int k = nb >> i;
        if (k & 1)
            ans[j] = 1;
        else
            ans[j] = 0;
    }
    return ans;
}
