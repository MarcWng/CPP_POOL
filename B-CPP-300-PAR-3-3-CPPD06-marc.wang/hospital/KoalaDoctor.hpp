/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaDoctor.hpp
*/

#include "KoalaNurse.hpp"

class KoalaDoctor
{
private:
    std::string name;
    bool work;
    bool destroy;
    void timeCheck();
public:
    KoalaDoctor(std::string name);
    ~KoalaDoctor();
    void diagnose(SickKoala *koala);
    std::string getName();
};
