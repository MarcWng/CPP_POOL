/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07A-marc.wang
** File description:
** KoalaBot.cpp
*/

#include "KoalaBot.hpp"
#include "Parts.hpp"

bool KoalaBot::isFunctional()
{
    return this->_functionnal;
}

std::string KoalaBot::serial()
{
    return this->_serial;
}
void KoalaBot::informations()
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status()
{
    return this->_arms.isFunctional() && this->_legs.isFunctional() && this->_head.isFunctional();
}

KoalaBot::KoalaBot()
{
    this->_serial = "Bob-01";
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &part)
{
    this->_arms = part;
}

void KoalaBot::setParts(const Legs &part)
{
    this->_legs = part;
}

void KoalaBot::setParts(const Head &part)
{
    this->_head = part;
}

void KoalaBot::swapParts(const Arms &part)
{
    this->_arms = part;
}

void KoalaBot::swapParts(const Legs &part)
{
    this->_legs = part;
}

void KoalaBot::swapParts(const Head &part)
{
    this->_head = part;
}