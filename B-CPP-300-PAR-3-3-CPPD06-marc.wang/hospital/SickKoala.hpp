/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** SickKoala.hpp
*/

#include <iostream>

class SickKoala
{
private:
    std::string name;
public:
    SickKoala();
    SickKoala(std::string name);
    std::string getName();
    ~SickKoala();
    void poke();
    bool takeDrug(std::string drug);
    void overDrive(std::string talk);
};
