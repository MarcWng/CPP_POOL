/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Toy.cpp
*/

#include "Toy.hpp"
#include <ostream>

Toy::Toy() : type(BASIC_TOY), name("toy"), pic(Picture())
{
}

Toy::Toy(const Toy &toy) : type(toy.type), name(toy.name), pic(toy.pic)
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

Toy &Toy::operator=(const Toy &toy)
{
    this->name = toy.name;
    this->pic = toy.pic;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Toy &t)
{
    stream << t.getName() << std::endl;
    stream << t.getAscii() << std::endl;
    return stream;
}

Toy &Toy::operator<<(const std::string &pic)
{
    this->pic.data = pic;
    return *this;
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

bool Toy::setAscii(std::string filename)
{
    return this->pic.getPictureFromFile(filename);
}

const std::string Toy::getAscii() const
{
    return this->pic.data;
}

void Toy::speak(std::string msg)
{
    std::cout << this->getName() << " \"" << msg << '"' << std::endl;
}