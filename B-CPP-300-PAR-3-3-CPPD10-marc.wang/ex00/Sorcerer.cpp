/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
**  Sorcerer.cpp
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, std::string title) : _title(title), _name(name)
{
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const
{
    return this->_name;
}
std::string Sorcerer::getTitle() const
{
    return this->_title;
}

std::ostream &operator<<(std::ostream &stream, const Sorcerer &s)
{
    stream << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!" << std::endl;
    return stream;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &peon) const
{
    peon.getPolymorphed();
}