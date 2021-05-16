/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** main.cpp
*/

#include <iostream>
#include <cstdlib>
#include "DomesticKoala.hpp"
#include "KoalaAction.hpp"

int main ()
{
    KoalaAction action;
    DomesticKoala dk (action) ;

    dk.learnAction('<', &KoalaAction::eat);
    dk.learnAction('>', &KoalaAction::goTo);
    dk.learnAction ('#', &KoalaAction::sleep);
    dk.learnAction ('X', &KoalaAction::reproduce);
    dk.doAction('>', "{EPITECH.}");
    dk.doAction('<', "a DoubleCheese");
    dk.doAction('X', "a Seagull");
    dk.doAction('#', "The end of the C++ pool, and an Astek burning on a stake");
    dk.unlearnAction('>');
    dk.doAction('>', "{EPITECH.}");
    dk.setKoalaAction(action);
    return 0;
}
