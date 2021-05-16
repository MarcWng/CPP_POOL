/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** OneTime.cpp
*/

#include "OneTime.hpp"
#include <cctype>
#include <cstring>

OneTime::OneTime(std::string key) : _i(0)
{
    for (int i = 0; key[i]; i++)
        tolower(key[i]);
    this->_key = key;
}

OneTime::~OneTime()
{
}

int getValue(char c)
{
    if (isupper(c))
        return static_cast<int>(c - 'A');
    return static_cast<int>(c - 'a');
}

void OneTime::encryptChar(char plainchar)
{
    int limit = 0;

    if (_i >= this->_key.size())
        _i = 0;
    limit = getValue(_key.at(_i));
    if (isupper(plainchar)) {
        for (int i = 0; i != limit; i++) {
            plainchar++;
            if (plainchar == 'Z' + 1)
                plainchar = 'A';
        }
    } else if (islower(plainchar)) {
        for (int i = 0; i != limit; i++) {
            plainchar++;
            if (plainchar == 'z' + 1)
                plainchar = 'a';
        }
    }
    std::cout << (char)plainchar;
    _i++;
}

void OneTime::decryptChar(char cipherchar)
{
   int limit = 0;

    if (_i >= this->_key.size())
        _i = 0;
    limit = getValue(_key.at(_i));
    if (isupper(cipherchar)) {
        for (int i = 0; i != limit; i++) {
            cipherchar--;
            if (cipherchar == 'A' - 1)
                cipherchar = 'Z';
        }
    } else if (islower(cipherchar)) {
        for (int i = 0; i != limit; i++) {
            cipherchar--;
            if (cipherchar == 'a' - 1)
                cipherchar = 'z';
        }
    }
    std::cout << (char)cipherchar;
    _i++;
}

void OneTime::reset()
{
    this->_i = 0;
}