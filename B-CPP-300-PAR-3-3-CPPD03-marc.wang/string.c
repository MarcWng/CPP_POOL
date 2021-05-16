/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD03-marc.wang
** File description:
** string.c
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_s = assign_s;
    this->assign_c = assign_c;
    this->append_c = append_c;
    this->append_s = append_s;
    this->at = at;
    this->clear = clear;
    this->size = size;
    this->compare_c = compare_c;
    this->compare_s = compare_s;
    this->size = size;
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
    this->find_s = find_s;
    this->find_c = find_c;
    this->insert_s = insert_s;
    this->insert_c = insert_c;
    this->to_int = to_int;
    // this->split_s = split_s;
}

void string_destroy(string_t *this)
{
    free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this->str != NULL)
        string_destroy(this);
    string_init(this, str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this->str != NULL)
        string_destroy(this);
    string_init(this, s);
}