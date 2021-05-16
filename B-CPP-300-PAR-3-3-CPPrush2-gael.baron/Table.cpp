/*
** EPITECH PROJECT, 2021
** ITable
** File description:
** functions
*/

#include "ITable.hpp"

PapaXmasTable::PapaXmasTable(void): tab(nullptr), _stuff(nullptr)
{
}

PapaXmasTable::PapaXmasTable(Object **stuff): tab(nullptr), _stuff(stuff)
{
}

PapaXmasTable::~PapaXmasTable(void)
{
}

Object **PapaXmasTable::look(void)
{
    if (this->tab && this->tab[0])
        for (int i = 0; tab[i]; i++)
            std::cout << tab[i] << std::endl;
    return (this->tab);
}

void PapaXmasTable::put(Object *obj)
{
    int i = 0;

    for (; this->tab[i]; i++);
    if (i >= 10) {
        delete (this->tab);
        return;
    }
    this->tab[i] = obj;
    this->tab[i + 1] = NULL;
}

void PapaXmasTable::take(Object *obj)
{
    for (int i = 0; this->tab[i]; i++)
        if (this->tab[i] == obj)
            delete (this->tab[i]);
}

ITable *createTable()
{
    return new PapaXmasTable;
}

void PapaXmasTable::collapse(void)
{
    delete (this->tab);
}
