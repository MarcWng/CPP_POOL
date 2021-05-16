/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** main.cpp
*/

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include <iostream>
#include <memory>

int main ()
{
    std::unique_ptr<ISquad> vlc (new Squad);

    vlc->push (new TacticalMarine);
    vlc -> push (new AssaultTerminator);

    std::cout << vlc->getCount() << std::endl;
    for (int i = 0; i < vlc->getCount(); i++) {
        const auto cur = vlc -> getUnit ( i ) ;
        cur -> battleCry () ;
        cur -> rangedAttack () ;
        cur -> meleeAttack () ;
    }
    return 0;
}
