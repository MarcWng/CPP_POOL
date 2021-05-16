/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02M-marc.wang
** File description:
** func_ptr.c
*/

#include <stdio.h>
#include <string.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int i = strlen(str) - 1;

    while (i >= 0) {
        printf("%c", str[i]);
        i--;
    }
    printf("\n");
}

void print_upper(const char *str)
{
    int len = strlen(str);

    for (int i = 0; i != len; i++)
        if (str[i] >= 97 && str[i] <= 122) {
            printf("%c", str[i] - 32);
        } else {
            printf("%c", str[i]);
        }
    printf("\n");
}

void print_42(const char *str)
{
    (void)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*func[4])(const char*);

    func[PRINT_42] = print_42;
    func[PRINT_NORMAL] = print_normal;
    func[PRINT_REVERSE] = print_reverse;
    func[PRINT_UPPER] = print_upper;
    (*func[action])(str);
}
