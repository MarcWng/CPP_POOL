/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _head(NULL), _size(size), _fruit_count(0)
{
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return this->_fruit_count;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *elem = new FruitNode();
    FruitNode *tail;

    if (this->nbFruits() > this->_size - 1)
        return false;
    elem->fruit = f;
    elem->next = NULL;
    if (this->_head == NULL) {
        this->_head = elem;
        this->_fruit_count++;
        return true;
    }
    tail = this->_head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = elem;
    this->_fruit_count++;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *temp = this->_head;

    if (this->_head == NULL) {
        return NULL;
    }
    this->_head = this->_head->next;
    this->_fruit_count--;
    return temp->fruit;
}

const FruitNode *FruitBox::head() const
{
    return this->_head;
}