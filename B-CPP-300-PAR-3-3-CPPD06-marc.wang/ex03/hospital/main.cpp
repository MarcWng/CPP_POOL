/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** main.cpp
*/

#include "KoalaNurse.hpp"

int main()
{
    KoalaNurse nurse = KoalaNurse(42);
    SickKoala koala = SickKoala("Gayel");
    std::string drug;

    drug = nurse.readReport("Gayel.report");
    nurse.giveDrug(drug, &koala);
}