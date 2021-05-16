/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** RAM.cpp
*/

#include "RAM.hpp"
#include <fstream>
#include <iostream>
#include <limits>

std::string RAM::refreshMem()
{
    unsigned long memory;
    std::string part;
    std::string ret = "RAM : ";
    std::ifstream file("/proc/meminfo");

    while (file >> part) {
        if (part == "MemTotal:" && file >> memory)
            this->MemTotal = memory;
        else if (part == "MemFree:" && file >> memory)
            this->MemFree = memory;
        else
            break;
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    ret.append(std::to_string(this->MemFree));
    ret.append("/");
    ret.append(std::to_string(this->MemTotal));
    ret.append(" KB");
    this->_info = ret;
    return ret;
}

RAM::RAM() : BaseInfo()
{
	this->_info = refreshMem();
    this->_moduleName = "RAM";
}

RAM::~RAM()
{
}