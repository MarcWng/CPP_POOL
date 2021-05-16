/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** MonitorCore.cpp
*/

#include "MonitorCore.hpp"
#include <numeric>
#include <fstream>

MonitorCore::MonitorCore(std::string info) : _show(true), _info(info), _name("")
{
    int space = info.find(" ", 0);
    int sum = 0;

    _name = this->_info.substr(0, space);
    if (_name.compare("cpu") == 0)
        space = space + 2;
    else
        space = space + 1;
    calculateUsage(info.substr(space));
}

void MonitorCore::calculateUsage(std::string str) 
{ 
    std::vector<size_t> list;
    float total_time = 0;
    float idle_time = 0;
    static float prev_idle = 0;
    static float prev_total = 0;
    size_t i = 0;

    while (i != std::string::npos) {
        list.push_back(stoi(str.substr(i, str.find(' ', i + 1) - i)));
        i = str.find(' ', i + 1);
    }
    idle_time = list[3] + list[4];
    total_time = std::accumulate(list.begin(), list.end(), 0);
    if (prev_idle == 0 && prev_total == 0)
        this->_usage = (float) 100 - (100 * (idle_time / total_time));
    else
        this->_usage = (float) 1 - (idle_time - prev_idle) / (total_time - prev_total) * 100;
}

float MonitorCore::getUsage() const
{
    return this->_usage;
}

void MonitorCore::setUsage(float usage)
{
    this->_usage = usage;
}

MonitorCore::~MonitorCore()
{
}

void MonitorCore::setInfo(std::string info)
{
    this->_info = info;
}

const std::string MonitorCore::getInfo() const
{
    return this->_info;
}

const std::string MonitorCore::getModuleName() const
{
    return this->_name;
}
