/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Woody.cpp
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string ascii) : Toy(WOODY, name, ascii)
{
}

Woody::~Woody()
{
}

void Woody::speak(std::string msg)
{
    std::cout << "WOODY: ";
    Toy::speak(msg);
}

bool Woody::speak_es(std::string msg)
{
    (void)msg;
    this->err.type = this->err.SPEAK;
    return false;
}