/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD03-marc.wang
** File description:
** test_main.c
*/

#include "string.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    string_t first_s;
    string_t second_s;

    string_init(&first_s, "123456789");
    string_init(&second_s, "caca");
    printf("first string : %s\n", first_s.str);
    // printf("second string : %s\n", second_s.str);

    //assign
    // first_s.assign_c(&first_s, str);
    // printf("if assign works, it should display (second) : %s\n", first_s.str);

    // append
    // first_s.append_s(&first_s, &second_s);
    // printf("if append works, it should display (firstsecond) : %s\n", first_s.str);

    //at
    // printf("if at works, it should display (first) : ");
    // for (int i = 0; i != strlen(first_s.str); i++)
    //     putchar(first_s.at(&first_s, i));
    // putchar('\n');

    // clear
    // first_s.clear(&first_s);
    // if (strlen(first_s.str) == 0)
    //     printf("clear works\n");
    // else
    //     printf("clear failed, size is : %d\n", strlen(first_s.str));

    //size
    // if (first_s.size(&first_s) == strlen(first_s.str))
    //     printf("size is okay\n");

    // compare
    // if (first_s.compare_s(&first_s, &first_copy_s) == 0)
    //     printf("identical is ok\n");
    // if (first_s.compare_s(&first_s, &second_s) != 0)
    //     printf("not identical is ok\n");

    //copy
    char *s = malloc(sizeof(char) * 20);

    printf("function ret = %d\n", first_s.copy(&first_s, s, 3, 1));
    puts(s);
    // c_str

    // const char *str = first_s.c_str(&first_s);
    // printf("should be (first) : %s\n", str);

    // empty
    // first_s.clear(&first_s);
    // if (first_s.empty(&first_s) == 1)
    //     printf("YES\n");
    // else
    //     printf("ntm gaël\n");

    //find
    // if (first_s.find_s(&first_s, &second_s, 0) != -1)
    //     printf("found !\n");
    // if (first_s.find_c(&first_s, s, 0) != -1)
    //     printf("found !\n");

    //insert
    // first_s.insert_s(&first_s, 4, &second_s);
    // printf("%s\n", first_s.str);
    string_destroy(&first_s);
    string_destroy(&second_s);
    return (0);
}