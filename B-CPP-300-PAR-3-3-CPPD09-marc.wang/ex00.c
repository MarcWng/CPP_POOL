/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** ex00.c
*/

#include "ex00.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void cthulhu_initializer(cthulhu_t *this);
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);

void sleeping(cthulhu_t *this)
{
    this->m_power = this->m_power + 42000;
    printf("%s sleeps\n", this->m_name);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power = this->m_power - 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);

}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(new));

    cthulhu_initializer(new);
    return new;
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));
    koala_initializer(new, name, is_a_legend);

    return new;
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    this->m_is_a_legend = _is_A_Legend;
    cthulhu_initializer(&this->m_parent);
    this->m_parent.m_name = strdup(_name);
    if (_is_A_Legend == 0)
        this->m_parent.m_power = 0;
    printf("Building %s\n", _name);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("----\nBuilding Cthulhu\n");
}

void eat(koala_t *this)
{
    this->m_parent.m_power = this->m_parent.m_power + 42;
    printf("%s eats\n", this->m_parent.m_name);
}
