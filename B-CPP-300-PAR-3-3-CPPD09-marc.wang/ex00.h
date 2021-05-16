/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** ex00.h
*/

#ifndef EX00_H
#define EX00_H

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
    struct cthulhu_s *(*new_cthulhu)();
}cthulhu_t;

typedef struct koala_s {
    cthulhu_t m_parent;
    char m_is_a_legend;
}koala_t;

void eat(koala_t *this);
koala_t *new_koala(char *name, char is_a_legend);
cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);

#endif