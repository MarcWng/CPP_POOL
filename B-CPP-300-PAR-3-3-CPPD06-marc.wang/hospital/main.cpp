/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** main.cpp
*/

#include "KoalaDoctor.hpp"

int main()
{
    KoalaDoctor doc = KoalaDoctor("Docteur");
    SickKoala koala = SickKoala("Gayel");
    std::string drug;
    srandom(time(0));

    doc.diagnose(&koala);
}