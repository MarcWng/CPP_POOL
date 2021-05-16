/*
** EPITECH PROJECT, 2021
** IElf
** File description:
** functions
*/

#include "IElf.hpp"

IElf::~IElf()
{
}

PapaXmasElf::PapaXmasElf()
{
}

PapaXmasElf::~PapaXmasElf()
{
}

Object **PapaXmasElf::look(ITable *table)
{
    return (table->look());
}

Object *PapaXmasElf::wrapMeThat(Object *toWrap)
{
    ((Box *)toWrap)->wrapMeThat(toWrap);
    ((GiftPaper *)toWrap)->wrapMeThat(toWrap);
    std::cout << "tuuuut tuuut tuut" << std::endl;
    return (toWrap);
}

const Object *PapaXmasElf::openBoxes(GiftPaper *gift)
{
    return (gift->openMe());
}

const Object *PapaXmasElf::openBoxes(Box *gift)
{
    return (gift->openMe());
}

void PapaXmasElf::PutOnBox(Box *toWrap, Object *obj)
{
    toWrap->wrapMeThat(obj);
}

void PapaXmasElf::closeBox(Box *toClose)
{
    if (toClose->isOpen())
        toClose->closeMe();
}

void PapaXmasElf::put(ITable *table, Object *obj)
{
    table->put(obj);
}

void PapaXmasElf::put(IConvoyer *belt, Object *obj)
{
    belt->put(obj);
}

void PapaXmasElf::take(ITable *table, Object *obj)
{
    table->take(obj);
}

void PapaXmasElf::take(IConvoyer *belt)
{
    std::cout << "whistles while working" << std::endl;
    belt->take();
}

Object *PapaXmasElf::buttonIN(IConvoyer *belt)
{
    if (belt->isActivated())
        return (belt->wrapElem(0));
    return (nullptr);
}

void PapaXmasElf::buttonOUT(IConvoyer *belt)
{
    belt->getOut();
}
