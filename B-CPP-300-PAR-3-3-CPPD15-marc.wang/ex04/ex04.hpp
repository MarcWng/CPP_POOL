/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** ex04.hpp
*/

#ifndef EX04_HPP
#define EX04_HPP
#include <iostream>

template<typename T>
class Tester
{
private:
public:
    Tester(){};
    ~Tester(){};
    bool equal(const T &a, const T &b);
};

template<typename T>
bool equal(const T &a, const T &b)
{
    if (a == b)
        return true;
    return false;
}

#endif
