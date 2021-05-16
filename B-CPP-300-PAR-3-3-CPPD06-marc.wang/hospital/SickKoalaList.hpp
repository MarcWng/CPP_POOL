/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** SickKoalaList.hpp
*/

#include "SickKoala.hpp"

class SickKoalaList
{
private:
    SickKoala *koala;
public:
    SickKoalaList(SickKoala *koala);
    ~SickKoalaList();
    SickKoalaList *next;
    bool isEnd();
    void append(SickKoalaList *next_koala);
    SickKoala *getFromName(std::string name);
    SickKoalaList *remove(SickKoalaList *to_rm);
    SickKoala *getContent();
    SickKoalaList *getNext();
    void dump();
};