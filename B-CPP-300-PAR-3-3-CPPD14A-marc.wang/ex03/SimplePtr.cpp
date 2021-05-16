/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14A-marc.wang
** File description:
** SimplePtr.cpp
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) :
    _rawPtr(rawPtr)
{
}
SimplePtr::~SimplePtr()
{
}

BaseComponent *SimplePtr::get() const
{
    return this->_rawPtr;
}