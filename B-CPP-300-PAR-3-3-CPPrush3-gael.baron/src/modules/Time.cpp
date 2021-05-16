/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** Time.cpp
*/

#include "Time.hpp"
#include <ctime>

Time::Time() : BaseInfo()
{
    std::time_t date_time = std::time(nullptr);
	this->_info = std::ctime(&date_time);
    this->_moduleName = "Time";
}

Time::~Time()
{
}