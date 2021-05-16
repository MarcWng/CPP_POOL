/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaDoctorList.hpp
*/

#include "KoalaDoctor.hpp"

class KoalaDoctorList
{
private:
    KoalaDoctor *doc;
public:
    KoalaDoctorList(KoalaDoctor *doc);
    ~KoalaDoctorList();
    KoalaDoctorList *next;
    bool isEnd();
    void append(KoalaDoctorList *next_doc);
    KoalaDoctor *getFromID(std::string name);
    KoalaDoctorList *remove(KoalaDoctorList *to_rm);
    KoalaDoctor *getContent();
    KoalaDoctorList *getNext();
    void dump();
};