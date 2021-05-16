/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** DomesticKoala.cpp
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(DomesticKoala const &koala) :
    _mptr(127), action(koala.action)
{
}

DomesticKoala::DomesticKoala(KoalaAction &action) :
    _mptr(127), action(action)
{
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &koala)
{
    this->_mptr = koala._mptr;
    return *this;
}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getActions() const
{
    return &this->_mptr;
}

void DomesticKoala::learnAction(unsigned char command, DomesticKoala::methodPointer_t action)
{
    this->_mptr[command] = action;
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    this->_mptr[command] = nullptr;
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    if (this->_mptr[command] != NULL)
        (this->action.*this->_mptr[command])(param);
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    this->_mptr.clear();
    this->action = action;
}
