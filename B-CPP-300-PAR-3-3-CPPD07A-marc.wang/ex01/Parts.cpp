/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07A-marc.wang
** File description:
** Parts.cpp
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functional)
{
    this->_name = "Arms";
    this->_serial = serial;
    this->_functionnal = functional;
}
Arms::~Arms()
{
}

Legs::Legs(std::string serial, bool functional)
{
    this->_name = "Legs";
    this->_serial = serial;
    this->_functionnal = functional;
}

Legs::~Legs()
{
}

Head::Head(std::string serial, bool functional)
{
    this->_name = "Head";
    this->_serial = serial;
    this->_functionnal = functional;
}

Head::~Head()
{
}

bool Arms::isFunctional()
{
    return this->_functionnal;
}

std::string Arms::serial()
{
    return this->_serial;
}
void Arms::informations()
{
    std::string status = "OK";

    if (this->_functionnal == false)
        status = "KO";
    std::cout << "\t[Parts] " << this->_name << " " << this->_serial << " status : " << status << std::endl;
}

bool Legs::isFunctional()
{
    return this->_functionnal;
}

std::string Legs::serial()
{
    return this->_serial;
}
void Legs::informations()
{
    std::string status = "OK";

    if (this->_functionnal == false)
        status = "KO";
    std::cout << "\t[Parts] " << this->_name << " " << this->_serial << " status : " << status << std::endl;
}

bool Head::isFunctional()
{
    return this->_functionnal;
}

std::string Head::serial()
{
    return this->_serial;
}
void Head::informations()
{
    std::string status = "OK";

    if (this->_functionnal == false)
        status = "KO";
    std::cout << "\t[Parts] " << this->_name << " " << this->_serial << " status : " << status << std::endl;
}