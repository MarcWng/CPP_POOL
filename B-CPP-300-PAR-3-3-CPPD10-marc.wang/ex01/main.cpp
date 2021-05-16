/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** main.cpp
*/

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"

int main ()
{
    const auto preda = new Character("Predator") ;
    const auto prey = new RadScorpion();
    const auto mutant = new SuperMutant();
    AWeapon * pr (new PlasmaRifle () ) ;
    AWeapon * pf (new PowerFist () ) ;
    preda->attack(mutant) ;
    preda -> equip ( pr ) ;
    std::cout << mutant->getHP() << std::endl;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    preda -> attack (mutant) ;
    std::cout << mutant->getHP() << std::endl;
    return 0;
}