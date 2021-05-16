/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** Encryption.cpp
*/

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod &encryptionMethod , methodPointer_t func) :
	eMethod(encryptionMethod), ptr(func)
{
}

Encryption::~Encryption()
{
}

void Encryption::operator()(char c)
{
	(this->eMethod.*ptr)(c);
}

void Encryption::encryptString(IEncryptionMethod& encryptionMethod, std::string const & data)
{
	encryptionMethod.reset();
	std::for_each(data.begin(), data.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
	std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod& encryptionMethod, std::string const & data)
{
	encryptionMethod.reset();
	std::for_each(data.begin(), data.end(), Encryption(encryptionMethod, &IEncryptionMethod::decryptChar));
	std::cout << std::endl;
}