/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** OneTime.hpp
*/

#ifndef ONETIME_HPP
#define ONETIME_HPP
#include <iostream>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod
{
    public:
    OneTime(std::string);
    ~OneTime();
    void encryptChar(char plainchar);
    void decryptChar(char cipherchar);
    void reset();
    private:
    std::string _key;
    int _i;
};

#endif