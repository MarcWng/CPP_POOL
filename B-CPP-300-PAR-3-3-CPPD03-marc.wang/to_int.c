/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD03-marc.wang
** File description:
** to_int.c
*/

#include "string.h"
#include <stdlib.h>

int to_int(const string_t *this)
{
    return(atoi(this->str));
}

// string_t **allocation(char *str, char separator)
// {
//     int i = 0;
//     int count = 0;
//     string_t **string = NULL;
//     int first_len = 0;
//     int j = 0;

//     while (str[i] != '\0') {
//         if (str[i] == separator)
//             count++;
//         i++;
//     }
//     string = malloc(sizeof(char*) * count);
//     return string;
// }

// string_t **split_s(const string_t *this, char separator)
// {
//     string_t **d_tab = allocation(this->str, separator);
//     int tab_i = 0;

//     if (d_tab == NULL)
//         return NULL;
//     while (this->str[tab_i] != NULL) {
//         while (this->str[tab_i] != separator) {
//             d_tab->this->str[tab_i]
//         }
//         tab_i++;
//     }
// }