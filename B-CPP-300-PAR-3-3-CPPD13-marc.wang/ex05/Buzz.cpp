/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string ascii) : Toy(BUZZ, name, ascii)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(std::string msg)
{
    std::cout << "BUZZ: ";
    Toy::speak(msg);
}

bool Buzz::speak_es(std::string msg)
{
    std::cout << "BUZZ: ";
    Toy::speak_es(msg);
    return true;
}