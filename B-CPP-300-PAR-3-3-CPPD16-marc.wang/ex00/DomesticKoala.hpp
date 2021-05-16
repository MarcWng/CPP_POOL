/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** DomesticKoala.hpp
*/

#ifndef DOMESTICKOALA_HPP
#define DOMESTICKOALA_HPP

#include <vector>
#include "KoalaAction.hpp"

class DomesticKoala
{
    public:
    using methodPointer_t = void (KoalaAction::*)(const std::string&);
    DomesticKoala();
    DomesticKoala(KoalaAction &action);
    DomesticKoala(const DomesticKoala &);
    DomesticKoala &operator=(const DomesticKoala &);
    ~DomesticKoala();
    const std::vector<methodPointer_t> *getActions() const;
    void learnAction(unsigned char command, methodPointer_t action);
    void unlearnAction(unsigned char command);
    void doAction(unsigned char command, const std::string &param);
    void setKoalaAction(KoalaAction &);

    private:
    std::vector<methodPointer_t> _mptr;
    KoalaAction action;
};

#endif