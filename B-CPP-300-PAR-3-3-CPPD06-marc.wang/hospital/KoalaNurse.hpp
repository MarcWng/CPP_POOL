/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaNurse.hpp
*/

#include <iostream>
#include "SickKoala.hpp"



class KoalaNurse
{
private:
    void timeCheck();
    bool check;
    bool destroying;
    int ID;
public:
    KoalaNurse(int ID);
    ~KoalaNurse();
    void giveDrug(std::string drug, SickKoala *koala);
    std::string readReport(std::string report);
    int getID();
};