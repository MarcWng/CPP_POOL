/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** IMonitorModule.hpp
*/

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP
#include <iostream>

class IMonitorModule
{
    public:
    virtual ~IMonitorModule(){}
    virtual const std::string getModuleName() const = 0;
    virtual const std::string getInfo() const = 0;
};

#endif