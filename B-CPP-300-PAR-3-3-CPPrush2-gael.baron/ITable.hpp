/*
** EPITECH PROJECT, 2021
** ITable
** File description:
** header
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "Objects.hpp"
#include <iostream>

class ITable
{
public:
    ~ITable(){};
    virtual Object **look(void) = 0;
    virtual void collapse(void) = 0;
    virtual void put(Object *obj) = 0;
    virtual void take(Object *obj) = 0;
};

class PapaXmasTable : public ITable
{
private:
    Object **tab;
    Object **_stuff;
public:
    PapaXmasTable(Object **stuff);
    PapaXmasTable();
    ~PapaXmasTable();
    Object **look(void);
    void collapse(void);
    void put(Object *obj);
    void take(Object *obj);
};

ITable *createTable();

#endif
