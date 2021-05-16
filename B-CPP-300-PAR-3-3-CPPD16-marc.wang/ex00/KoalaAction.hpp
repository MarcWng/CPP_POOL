/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** KoalaAction.hpp
*/

#ifndef KOALAACTION_HPP
#define KOALAACTION_HPP
#include <iostream>

class KoalaAction
{
public:
    KoalaAction(){};
    ~KoalaAction(){};
    void eat(const std::string &str);
    void goTo(const std::string &str);
    void sleep(const std::string &str);
    void reproduce(const std::string &str);
};

#endif