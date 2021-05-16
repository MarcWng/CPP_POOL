/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy"), pic(Picture())
{
}

Toy::Toy(ToyType type, std::string name, std::string filename) :
    type(type), name(name)
{
    setAscii(filename);
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return this->type;
}

const std::string Toy::getName() const
{
    return this->name;
}

void Toy::setName(std::string name)
{
    this->name = name;
}

bool Toy::setAscii(const std::string filename)
{
    return this->pic.getPictureFromFile(filename);
}

const std::string Toy::getAscii() const
{
    return this->pic.data;
}
