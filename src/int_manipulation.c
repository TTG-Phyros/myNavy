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

int my_compute_power_it (int nb, int p)
{
    int pow = nb;
    if (p > 0) {
        for (int i = 1; i != p; i++)
            nb = nb * pow;
        return nb;
    } else if (p < 0) {
        return 0;
    } else {
        return 1;
    }
}

int binary_to_decimal(long long int nb)
{
    int ans = 0, temp;
    for (int i = 0; nb != 0; i++) {
        temp = nb % 10;
        nb /= 10;
        ans += temp * my_compute_power_it(2, i);
    }
    return ans;
}
