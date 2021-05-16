/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaDoctorList.cpp
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doc)
{
    this->doc = doc;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    if (this->next == NULL) {
        if (this->next->doc == nullptr)
        return true;
    }
    return false;
}

void KoalaDoctorList::append(KoalaDoctorList *next_doc)
{
    this->next = next_doc;
}

KoalaDoctor *KoalaDoctorList::getFromID(std::string name)
{
    KoalaDoctorList* cpy = this;

    while (cpy != NULL) {
        if (this->doc->getName().compare(name) == 0)
            return (this->doc);
        cpy = cpy->next;
    }
    return NULL;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *to_rm)
{
    KoalaDoctorList *cpy = this;

    if (cpy == to_rm || cpy == NULL)
        return NULL;
    while (cpy->next != NULL) {
        if (cpy->next == to_rm)
            cpy->next == cpy->next->next;
        cpy = cpy->next;
    }
    return (this);
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (this->doc);
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    if (this->next == NULL) {
        return nullptr;
    }
    return (this->next);
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *head = this;

    std::cout << "Doctors: ";
    while (head) {
        if (this->doc->getName().empty() == true)
            std::cout << "[nullptr]";
        else
            std::cout << this->doc->getName();
        head = head->next;
        if (head == NULL)
            std::cout << "." << std::endl;
        else
            std::cout << ", ";
    }
}