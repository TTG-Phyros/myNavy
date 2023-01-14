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

int *decimal_to_binary(int nb, int len)
{
    int *ans = malloc(sizeof(int) * (len + 1));
    for (int i = len, j = 0; i >= 0; i--, j++) {
        int k = nb >> i;
        if (k & 1)
            ans[j] = 1;
        else
            ans[j] = 0;
    }
    return ans;
}

int binary_to_decimal(int *list_nb, int len)
{
    int ans = 0, ac_mul = 1;
    for (int i = len; i > 0; i--) {
        ans += list_nb[i] * ac_mul;
        ac_mul *= 2;
    }
    return ans;
}
