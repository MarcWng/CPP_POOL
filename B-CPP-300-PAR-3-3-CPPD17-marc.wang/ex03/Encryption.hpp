/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** Encryption .hpp
*/

#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP
#include "IEncryptionMethod.hpp"
#include <algorithm>
#include <iostream>

class Encryption 
{
    public:
    using methodPointer_t = void (IEncryptionMethod::*)(char);
    Encryption(IEncryptionMethod &encryptionMethod , methodPointer_t ptr);
    ~Encryption();
    void operator()(char c);
    static void encryptString(IEncryptionMethod &encryptionMethod, std::string const &);
    static void decryptString(IEncryptionMethod &encryptionMethod, std::string const &);

    private:
    IEncryptionMethod &eMethod;
    methodPointer_t ptr;
};

#endif