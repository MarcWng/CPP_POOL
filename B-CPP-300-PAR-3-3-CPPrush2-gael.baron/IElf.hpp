/*
** EPITECH PROJECT, 2021
** IElf
** File description:
** header
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "ITable.hpp"
#include "GiftPaper.hpp"
#include "IConvoyerBelt.hpp"

class IElf
{
public:
    ~IElf();
    virtual Object **look(ITable *table) = 0;
    virtual Object *wrapMeThat(Object *toWrap) = 0;
    virtual const Object *openBoxes(GiftPaper *gift) = 0;
    virtual const Object *openBoxes(Box *gift) = 0;
    virtual void PutOnBox(Box *toWrap, Object *obj) = 0;
    virtual void closeBox(Box *toClose) = 0;
    virtual void put(ITable *table, Object *obj) = 0;
    virtual void put(IConvoyer *belt, Object *obj) = 0;
    virtual void take(ITable *table, Object *obj) = 0;
    virtual void take(IConvoyer *belt) = 0;
    virtual Object *buttonIN(IConvoyer *belt) = 0;
    virtual void buttonOUT(IConvoyer *belt) = 0;
};

class PapaXmasElf : public IElf
{
public:
    PapaXmasElf();
    ~PapaXmasElf();
    Object **look(ITable *table);
    Object *wrapMeThat(Object *toWrap);
    const Object *openBoxes(GiftPaper *gift);
    const Object *openBoxes(Box *gift);
    void PutOnBox(Box *toWrap, Object *obj);
    void closeBox(Box *toClose);
    void put(ITable *table, Object *obj);
    void put(IConvoyer *belt, Object *obj);
    void take(ITable *table, Object *obj);
    void take(IConvoyer *belt);
    Object * buttonIN(IConvoyer *belt);
    void buttonOUT(IConvoyer *belt);
};

#endif
