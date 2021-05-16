/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD03-marc.wang
** File description:
** append.c
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>

void append_s(string_t *this, const string_t *ap)
{
    char *temp = malloc(sizeof(char) *
    (strlen(this->str) + strlen(ap->str) + 1));

    temp = strcpy(temp, this->str);
    temp = strcat(temp, ap->str);
    if (this->str != NULL)
        string_destroy(this);
    this->str = strdup(temp);
    free(temp);
}

void append_c(string_t *this, const char *ap)
{
    char *temp = malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));

    temp = strcpy(temp, this->str);
    temp = strcat(temp, ap);
    if (this->str != NULL)
        string_destroy(this);
    this->str = strdup(temp);
    free(temp);
}

char at(const string_t *this, size_t pos)
{
    if (strlen(this->str) < pos || this->str[pos] == '\0')
        return -1;
    return (this->str[pos]);
}

void clear(string_t *this)
{
    if (strlen(this->str) != 0)
        memset(this->str, 0, strlen(this->str));
}

int size(const string_t *this)
{
    if (this->str == NULL)
        return -1;
    return strlen(this->str);
}

