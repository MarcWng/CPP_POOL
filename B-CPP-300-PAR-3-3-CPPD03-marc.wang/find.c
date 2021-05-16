/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD03-marc.wang
** File description:
** find.c
*/

#include "string.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool verify(char *this, char const *str, int len)
{
    if (strncmp(str, this, len) == 0)
        return true;
    return false;
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    bool found = false;
    int i = 0;
    int len = strlen(str->str);

    if (pos > strlen(this->str) || len > (int)strlen(this->str) || str == NULL)
        return (-1);
    while (this->str[pos + i] != '\0' && found == false) {
        if (this->str[pos + i] == str->str[0])
            found = verify(&this->str[pos + i], str->str, len);
        i++;
    }
    if (found == true)
        return (pos + i);
    else
        return -1;
}

int find_c(const string_t *this, const char *str , size_t pos)
{
    bool found = false;
    int i = 0;
    int len = strlen(str);

    if (pos > strlen(this->str) || len > (int)strlen(this->str) || str == NULL)
        return (-1);
    while (this->str[pos + i] != '\0' && found == false) {
        if (this->str[pos + i] == str[0])
            found = verify(&this->str[pos + i], str, len);
        i++;
    }
    if (found == true)
        return (pos + i);
    else
        return -1;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    int len_to_cpy = 0;
    char *second_part_str = NULL;
    char *first_part_str = NULL;

    if (pos > strlen(this->str)) {
        append_s(this, str);
        return;
    }
    len_to_cpy = strlen(&(this->str)[pos]);
    second_part_str = malloc(sizeof(char) * len_to_cpy);
    first_part_str = malloc(sizeof(char) * strlen(this->str) - len_to_cpy);
    if (first_part_str == NULL || second_part_str == NULL)
        return;
    this->copy(this, second_part_str, len_to_cpy, pos);
    this->copy(this, first_part_str, strlen(this->str) - len_to_cpy, 0);
    this->assign_c(this, first_part_str);
    this->append_s(this, str);
    this->append_c(this, second_part_str);
    free(first_part_str);
    free(second_part_str);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    int len_to_cpy = 0;
    char *second_part_str = NULL;
    char *first_part_str = NULL;
    if (pos > strlen(this->str)) {
        append_c(this, str);
        return;
    }
    len_to_cpy = strlen((&this->str)[pos]);
    second_part_str = malloc(sizeof(char) * len_to_cpy);
    first_part_str = malloc(sizeof(char) * strlen(this->str) - len_to_cpy);
    if (first_part_str == NULL || second_part_str == NULL)
        return;
    this->copy(this, second_part_str, len_to_cpy, pos);
    this->copy(this, first_part_str, strlen(this->str) - len_to_cpy, 0);
    this->assign_c(this, first_part_str);
    this->append_c(this, str);
    this->append_c(this, second_part_str);
    free(first_part_str);
    free(second_part_str);
}