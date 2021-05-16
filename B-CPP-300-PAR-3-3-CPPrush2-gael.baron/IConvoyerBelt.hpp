/*
** EPITECH PROJECT, 2021
** IConvoyer
** File description:
** header
*/

#ifndef ICONVOYERBELT_HPP_
#define ICONVOYERBELT_HPP_

#include "Objects.hpp"
#include "GiftPaper.hpp"
#include "Wrap.hpp"

enum ButtonSetted
{
    IN,
    OUT
};

class IConvoyer
{
public:
    ~IConvoyer(){};
    virtual Object *wrapElem(int wrapper_pos) = 0;
    virtual void activateButtons(void) = 0;
    virtual void put(Object *obj) = 0;
    virtual Object *take(void) = 0;
    virtual bool isActivated(void) = 0;
    virtual Object *getElem(void) = 0;
    virtual void getOut(void) = 0;
};

class PapaXmasConveyorBelt : public IConvoyer
{
private:
    ButtonSetted _buttonSetted;
    Object *obj;
    Object **_items;
    bool buttonActivated = false;

public:
    PapaXmasConveyorBelt(Object **stuff);
    PapaXmasConveyorBelt();
    ~PapaXmasConveyorBelt();
    Object *wrapElem(int wrapper_pos);
    void activateButtons(void);
    void put(Object *obj);
    Object *take(void);
    bool isEmpty(void) const;
    void getOut(void);
    bool isActivated(void);
    Object *getElem(void);
};

IConvoyer *createConveyorBelt();

#endif
