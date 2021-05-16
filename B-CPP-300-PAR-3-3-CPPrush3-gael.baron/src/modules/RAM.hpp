/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** RAM.hpp
*/

#ifndef RAM_HPP
#define RAM_HPP
#include "BaseInfo.hpp"

class RAM : public BaseInfo
{
    public:
    RAM();
    ~RAM();
    std::string refreshMem();
    private:
    unsigned long MemTotal;
    unsigned long MemFree;

};

#endif