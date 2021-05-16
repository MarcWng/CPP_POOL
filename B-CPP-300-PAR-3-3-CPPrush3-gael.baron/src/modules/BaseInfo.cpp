    int set_info();
/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** BaseInfo.cpp
*/

#include "BaseInfo.hpp"
#include <exception>

BaseInfo::BaseInfo() :
    _show(true), _info("info"), _moduleName("BaseInfo")
{
}

BaseInfo::~BaseInfo()
{
}

BaseInfo::BaseInfo(const BaseInfo &info)
{
    this->_info = info._info;
    this->_info = info._show;
}

BaseInfo &BaseInfo::operator=(const BaseInfo &info)
{
    this->_info = info._info;
    this->_info = info._show;
    return *this;
}

void BaseInfo::setShow(bool state)
{
    this->_show = state;
}

bool BaseInfo::getShow() const
{
    return this->_show;
}

const std::string BaseInfo::getInfo() const
{
    return this->_info;
}

const std::string BaseInfo::getModuleName() const
{
    return this->_moduleName;
}
