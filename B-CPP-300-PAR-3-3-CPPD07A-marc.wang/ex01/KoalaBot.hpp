/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07A-marc.wang
** File description:
** KoalaBot.hpp
*/

#ifndef KOALA_BOT_HPP
#define KOALA_BOT_HPP

#include "Parts.hpp"

class Arms;
class Legs;
class Head;

class KoalaBot
{
private:
    Arms _arms;
    Legs _legs;
    Head _head;
protected:
    std::string _name;
    std::string _serial;
    bool _functionnal;
public:
    KoalaBot();
    ~KoalaBot();
    bool isFunctional();
    std::string serial();
    void informations();
    void setParts(const Arms &part);
    void setParts(const Legs &part);
    void setParts(const Head &part);
    void swapParts(const Arms &part);
    void swapParts(const Legs &part);
    void swapParts(const Head &part);
    bool status();
};

#endif