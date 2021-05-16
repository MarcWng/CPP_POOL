/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD08-marc.wang
** File description:
** main.cpp
*/

#include "Droid.hpp"

int main()
{
    Droid d;
    Droid d1("Avenger");
    size_t Durasel = 200;
    std :: cout << d << std :: endl ;
    std :: cout << d1 << std :: endl ;
    
    d . setStatus (new std::string("Kill Kill Kill!"));
    d = d1;
    d << Durasel ;
    std::cout << d << "--" << Durasel << std::endl ;
    Droid d2 = d ;
    std::cout << "Ok! Kill 'em all!" << std::endl;    
    d.setId("Rex");
    if (d2 != d)
        std::cout << "Nice to meet you " << d.getId() << "!" << std::endl;
    else
        std::cout << "You have an Identity crysis!" << std::endl;
    d1 << Durasel;
    d2 << Durasel;
    d << Durasel;
    std::cout << d << std::endl;
    d << Durasel;
    std::cout << d << std::endl;
    d << Durasel;
    std::cout << d << std::endl;
    d << Durasel;
    std::cout << d << std::endl;
    return 0;
}