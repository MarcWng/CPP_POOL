/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Squad.cpp
*/

#include "Squad.hpp"

Squad::Squad() : next_unit(nullptr), _marine(nullptr)
{
}

Squad::Squad(const Squad *sq)
{
    if (this->_marine != nullptr)
        delete this->_marine;
    this->_marine = sq->_marine;
}

Squad::~Squad()
{
}

int Squad::getCount() const
{
    int i = 0;
    Squad *tmp = new Squad(this);

    while (tmp->next_unit != nullptr) {
        tmp = tmp->next_unit;
        i++;
    }
    return i;
}

ISpaceMarine *Squad::getUnit(int index)
{
    Squad *tmp(this);

    for (int i = 0; i != index && tmp->next_unit != nullptr; i++)
        tmp->next_unit = next_unit;
    return tmp->_marine;
}

int Squad::push(ISpaceMarine* space_m)
{
    Squad *tail = this;
    int new_size = 0;

    if (this->_marine == nullptr)
        return 0;
    while (tail->next_unit != nullptr) {
        new_size = new_size + 1;
        tail = tail->next_unit;
    }
    tail->next_unit = new Squad();
    tail->next_unit->_marine = space_m;
    return new_size;
}