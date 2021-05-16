/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Skat.cpp
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
:   _name(name), _stimPaks(stimPaks)
{
}

// Skat::Skat(const std::string &name = "bob")
// {
//     this->_name = name;
//     this->_stimPaks = 15;
// }

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return this->_stimPaks;
}

const std::string& Skat::name()
{
    return this->_name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (this->_stimPaks < number)
        std::cout << "Don't be greedy" << std::endl;
    else {
        stock = stock + number;
        this->_stimPaks = this->_stimPaks - number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    this->_stimPaks =+ number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks > 0)
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->stimPaks() << " stimpaks remaining sir!" << std::endl;
}