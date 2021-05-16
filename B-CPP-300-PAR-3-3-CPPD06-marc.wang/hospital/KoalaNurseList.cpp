/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaNurseList.cpp
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse)
{
    this->nurse = nurse;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    if (this->next == NULL) {
        if (this->next->nurse == nullptr)
        return true;
    }
    return false;
}

void KoalaNurseList::append(KoalaNurseList *next_nurse)
{
    this->next = next_nurse;
}

KoalaNurse *KoalaNurseList::getFromID(int ID)
{
    KoalaNurseList* cpy = this;

    while (cpy != NULL) {
        if (this->nurse->getID()== ID)
            return (this->nurse);
        cpy = cpy->next;
    }
    return NULL;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *to_rm)
{
    KoalaNurseList *cpy = this;

    if (cpy == to_rm || cpy == NULL)
        return NULL;
    while (cpy->next != NULL) {
        if (cpy->next == to_rm)
            cpy->next == cpy->next->next;
        cpy = cpy->next;
    }
    return (this);
}

KoalaNurse *KoalaNurseList::getContent()
{
    return (this->nurse);
}

KoalaNurseList *KoalaNurseList::getNext()
{
    if (this->next == NULL) {
        return nullptr;
    }
    return (this->next);
}

void KoalaNurseList::dump()
{
    KoalaNurseList *head = this;

    std::cout << "Nurses: ";
    while (head) {
        if (this->nurse->getID() == 0)
            std::cout << "[nullptr]";
        else
            std::cout << this->nurse->getID();
        head = head->next;
        if (head == NULL)
            std::cout << "." << std::endl;
        else
            std::cout << ", ";
    }
}