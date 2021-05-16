/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** Hostname.cpp
*/

#include "Hostname.hpp"
#include <unistd.h>
#include <iostream>

Hostname::Hostname() : BaseInfo()
{
    char hostname[100];

	if (gethostname(hostname, 100) == -1) {
			std::cerr << "Error print with basic cout" << std::endl;
		}
	this->_info = hostname;
    this->_moduleName = "Hostname";
}

Hostname::~Hostname()
{
}

const std::string Hostname::getInfo() const
{
    return this->_info;
}
