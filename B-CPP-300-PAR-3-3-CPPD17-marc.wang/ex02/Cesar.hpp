/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** Cesar.hpp
*/

#ifndef CESAR_HPP
#define CESAR_HPP

#include "IEncryptionMethod.hpp"
#include <list>

class Cesar : public IEncryptionMethod
{
    public:
    Cesar();
    ~Cesar();
    void encryptChar(char plainchar);
    void decryptChar(char cipherchar);
    void reset();

    private:
    int shift_len;
    const std::list<char> alphabet;
};


#endif