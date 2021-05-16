/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** Cesar.cpp
*/

#include "Cesar.hpp"
#include <iostream>
#include <ctype.h>

Cesar::Cesar() : shift_len(3)
{
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    for (int i = 0; i != this->shift_len; i++) {
        if (isalpha(plainchar) == false)
            break;
        plainchar++;
        if (plainchar == 'Z' + 1)
            plainchar = 'A';
        if (plainchar == 'z' + 1)
            plainchar = 'a';
    }
    std::cout << plainchar;
    if (this->shift_len == 26)
        this->shift_len = 1;
    else
        this->shift_len++;
}

void Cesar::decryptChar(char cipherchar)
{
    for (int i = 0; i != this->shift_len; i++) {
        if (isalpha(cipherchar) == false)
            break;
        cipherchar--;
        if (cipherchar == 'A' - 1)
            cipherchar = 'Z';
        if (cipherchar == 'a' - 1)
            cipherchar = 'z';
    }
    std::cout << cipherchar;
    if (this->shift_len == 26)
        this->shift_len = 1;
    else
        this->shift_len++;
}

void Cesar::reset()
{
    this->shift_len = 3;
}