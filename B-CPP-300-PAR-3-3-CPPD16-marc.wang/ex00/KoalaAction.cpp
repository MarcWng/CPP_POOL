/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** KoalaAction.cpp
*/

#include "KoalaAction.hpp"

void KoalaAction::eat(const std::string &str)
{
    std::cout << "I eat :" << str << std::endl;
}

void KoalaAction::goTo(const std::string &str)
{
    std::cout << "I go to :" << str << std::endl;
}
void KoalaAction::sleep(const std::string &str)
{
    std::cout << "I sleep, and dream of: " << str << std::endl;
}
void KoalaAction::reproduce(const std::string &str)
{
    std::cout << "I attempt to reproduce with:" << str << std::endl;
}
