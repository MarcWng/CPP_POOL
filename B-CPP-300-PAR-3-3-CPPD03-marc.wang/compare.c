/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD03-marc.wang
** File description:
** compare.c
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t n_res = 0;

    if (pos > strlen(this->str))
        return 0;

    while (n_res < n && this->str[pos + n_res] != '\0') {
        s[n_res] = this->str[pos + n_res];
        n_res++;
    }
    if (strlen(s) < n) {
        s[n_res] = '\0';
        n_res++;
    }
    return (n_res);
}

const char *c_str(const string_t * this)
{
    return (this->str);
}

int empty(const string_t *this)
{
    if (strlen(this->str) == 0)
        return 1;
    return 0;
}
