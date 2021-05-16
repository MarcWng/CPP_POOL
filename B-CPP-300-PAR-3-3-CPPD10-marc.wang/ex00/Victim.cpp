/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Victim.cpp
*/

#include "Victim.hpp"

Victim::Victim(const std::string &name) : _name(name)
{
    std::cout << "Some random victim called " << this->_name <<" just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Victim &v)
{
    stream << "I'm " << v.getName() << " and I like otters!" << std::endl;
    return stream;
}

void Victim::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a cute little sheep!" << std::endl;
}

const std::string Victim::getName() const
{
    return this->_name;
}