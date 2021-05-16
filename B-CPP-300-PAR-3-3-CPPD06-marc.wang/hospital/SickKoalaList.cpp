/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** SickKoalaList.cpp
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    this->koala = koala;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (this->next == NULL) {
        if (this->next->koala == nullptr)
        return true;
    }
    return false;
}

void SickKoalaList::append(SickKoalaList *next_koala)
{
    this->next = next_koala;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList* cpy = this;

    while (cpy != NULL) {
        if (this->koala->getName().compare(name) == 0)
            return (this->koala);
        cpy = cpy->next;
    }
    return NULL;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *to_rm)
{
    SickKoalaList *cpy = this;

    if (cpy == to_rm || cpy == NULL)
        return NULL;
    while (cpy->next != NULL) {
        if (cpy->next == to_rm)
            cpy->next == cpy->next->next;
        cpy = cpy->next;
    }
    return (this);
}

SickKoala *SickKoalaList::getContent()
{
    return (this->koala);
}

SickKoalaList *SickKoalaList::getNext()
{
    if (this->next == NULL) {
        return nullptr;
    }
    return (this->next);
}

void SickKoalaList::dump()
{
    SickKoalaList *head = this;

    std::cout << "Patients: ";
    while (head) {
        if (this->koala->getName().empty() == true)
            std::cout << "[nullptr]";
        else
            std::cout << this->koala->getName();
        head = head->next;
        if (head == NULL)
            std::cout << "." << std::endl;
        else
            std::cout << ", ";
    }
}