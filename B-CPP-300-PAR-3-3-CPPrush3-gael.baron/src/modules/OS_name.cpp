/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** OS_name.cpp
*/

#include "OS_name.hpp"
#include <sys/utsname.h>

OS_name::OS_name() : BaseInfo()
{
    struct utsname os;

    if (uname(&os)) 
        throw (std::invalid_argument("Structure utsname error"));
    this->_info = os.sysname;
    this->_info.append(" ");
    this->_info.append(os.release);
    this->_info.append(" ");
    this->_info.append(os.machine);
    this->_moduleName = "OS";
}

OS_name::~OS_name()
{
}