/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** LittleHand.cpp
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    const struct FruitNode *tmp = unsorted.head();
    int i = 0;

    if (unsorted.head() == NULL)
        return;
    while (tmp != NULL && i != unsorted.nbFruits()) {
        if (tmp->fruit->getName().compare("lime") == 0 && limes.getSize() != limes.nbFruits())
            limes.putFruit(unsorted.pickFruit());
        if (tmp->fruit->getName().compare("lemon") == 0 && lemons.getSize() != lemons.nbFruits())
            lemons.putFruit(unsorted.pickFruit());
        if (tmp->fruit->getName().compare("banana") == 0 && bananas.getSize() != bananas.nbFruits())
            bananas.putFruit(unsorted.pickFruit());
        tmp = tmp->next;
        i++;
    }
}

FruitBox * const *LittleHand::organizeCoconut(Coconut const *const *coconuts)
{
    int nb_coco = 0;
    int i = 0;
    int j = 0;

    while (coconuts[nb_coco] != NULL)
        nb_coco++;
    FruitBox **box = new FruitBox*[nb_coco];
    while(i != nb_coco / 6) {
        if (i != nb_coco / 6)
            box[i] = new FruitBox(6);
        else
            box[i] = new FruitBox(nb_coco % 6);
        while (coconuts[j]) {
            box[i]->putFruit(const_cast<Coconut*>(coconuts[j]));
            j++;
        }
        i++;
    }
    return box;
}