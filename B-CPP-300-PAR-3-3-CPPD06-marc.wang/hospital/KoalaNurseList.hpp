/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaNurseList.hpp
*/

#include "KoalaNurse.hpp"

class KoalaNurseList
{
private:
    KoalaNurse *nurse;
public:
    KoalaNurseList(KoalaNurse *nurse);
    ~KoalaNurseList();
    KoalaNurseList *next;
    bool isEnd();
    void append(KoalaNurseList *next_nurse);
    KoalaNurse *getFromID(int ID);
    KoalaNurseList *remove(KoalaNurseList *to_rm);
    KoalaNurse *getContent();
    KoalaNurseList *getNext();
    void dump();
};