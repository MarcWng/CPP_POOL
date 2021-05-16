/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** SickKoala.cpp
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (!drug.compare("Mars")) {
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" << std::endl;
        return true;
    } else if (!drug.compare("Kinder")) {
        std::cout << "Mr." << this->name << ": There is a toy inside!" << std::endl;
        return true;
    } else
        std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return false;
}

void SickKoala::overDrive(std::string talk)
{
    int found = 0;

    found = talk.find("Kreog!");
    while (found != std::string::npos) {
        talk.replace(found, 6, "1337!");
        found = talk.find("Kreog!");
    }
    std::cout << "Mr." << this->name << ": " << talk << std::endl;
}

std::string SickKoala::getName()
{
    return (this->name);
}
