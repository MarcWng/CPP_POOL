/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** ConvoyerBelt.cpp
*/

#include "IConvoyerBelt.hpp"
#include "GiftPaper.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt(void):obj(NULL), _items(NULL)
{
}

PapaXmasConveyorBelt::PapaXmasConveyorBelt(Object **stuff):obj(NULL), _items(stuff)
{
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt(void)
{
}

bool PapaXmasConveyorBelt::isEmpty(void) const
{
    if (this->obj)
        return (true);
    return (false);
}

Object *PapaXmasConveyorBelt::wrapElem(int wrapper_pos)
{
    if (this->_items[wrapper_pos] && this->obj) {
        if ((this->_items[wrapper_pos]->getTitle().compare("GiftPaper") && this->obj->getTitle().compare("Box")) ||
        ((this->_items[wrapper_pos]->getTitle().compare("Box")) && !this->obj->getTitle().compare("GiftPaper"))) {
            if (this->_items[wrapper_pos]->getTitle().compare("GiftPaper")) {
                ((GiftPaper*)this->_items[wrapper_pos])->wrapMeThat((this->obj));
                return ((GiftPaper*)this->_items[wrapper_pos]);
            } else {
                ((Box*)this->_items[wrapper_pos])->wrapMeThat((this->obj));
                return ((Box*)this->_items[wrapper_pos]);
            }
        }
    } else {
        std::cerr << "Wrong wrapping" << std::endl;
    }
    return nullptr;
}

void PapaXmasConveyorBelt::getOut(void)
{
    if (this->buttonActivated && this->obj)
        delete(this->obj);
    else if (!this->buttonActivated)
        std::cerr << "Error: Buttons aren't activated !" << std::endl;
    else
        std::cerr << "Error: There isn't any object to send" << std::endl;
}

void PapaXmasConveyorBelt::activateButtons(void)
{
    this->buttonActivated = true;
}

void PapaXmasConveyorBelt::put(Object *obj)
{
    if (this->obj != NULL) {
        std::cerr << "Error: no available place" << std::endl;
        return;
    }
    this->obj = obj;
}

Object *PapaXmasConveyorBelt::take(void)
{
    Object *newObj;

    if (this->obj) {
        newObj = new Object (this->obj);
        delete(this->obj);
        return (newObj);
    }
    std::cerr << "Error: no object to take" << std::endl;
    return (NULL);
}

bool PapaXmasConveyorBelt::isActivated()
{
    return (this->buttonActivated);
}

Object *PapaXmasConveyorBelt::getElem()
{
    return (this->obj);
}

IConvoyer *createConveyorBelt()
{
    Object **obj = new Object*;

    obj[0] = new Box();
    obj[1] = new GiftPaper();
    obj[2] = new Box();
    obj[3] = new GiftPaper();
    return new PapaXmasConveyorBelt(obj);
}
