/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Peon.cpp
*/

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}