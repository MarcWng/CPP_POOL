/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD08-marc.wang
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

Droid::Droid(std::string serial) :
    Attack(25), Toughness(15)
{
    this->Id = serial;
    this->Energy = 50;
    this->Status = new std::string("Standing by");
    this->BattleData = new DroidMemory();
    std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &d2) :
    Attack(d2.Attack), Toughness(d2.Toughness)
{
    this->Id = d2.Id;
    this->Energy = d2.Energy;
    if (d2.Status)
        this->Status = d2.Status;
    else
        this->Status = new std::string("Standing by");
    this->BattleData = d2.BattleData;
    std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return this->Id;
}
size_t Droid::getEnergy() const
{
    return this->Energy;
}
size_t Droid::getAttack() const
{
    return this->Attack;
}
size_t Droid::getToughness() const
{
    return this->Toughness;
}
std::string *Droid::getStatus() const
{
    return this->Status;
}

DroidMemory *Droid::getBattleData() const
{
    return this->BattleData;
}

void Droid::setId(std::string Id)
{
    this->Id = Id;
}
void Droid::setEnergy(size_t Energy)
{
    this->Energy = Energy;
}
void Droid::setStatus(std::string *status)
{
    this->Status = status;
}

void Droid::setBattleData(DroidMemory* b_data)
{
    this->BattleData = b_data;
}

bool Droid::operator==(const Droid &d2) const
{
    if (this->Status == d2.Status)
        return true;
    return false;
}

bool Droid::operator!=(const Droid &d2) const
{
    if (this->Status == d2.Status)
        return false;
    return true;
}

Droid &Droid::operator<<(size_t energy)
{
    if (this->Energy >= 100 || this->Energy <= 0) {
        return *this;
    }
    if (this->Energy + energy >= 100) {
        this->Energy = 100;
        energy = 100 - this->Energy;
        return *this;
    }
    this->Energy = this->Energy + energy;
    energy =- this->Energy - energy;
    return *this;
}

Droid &Droid::operator=(const Droid &d2)
{
    this->Energy = d2.Energy;
    this->Id = d2.Id;
    if (this->Status)
        delete this->Status;
    this->Status = new std::string(*(d2.Status));
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Droid &d2)
{
    std::string const *status = d2.getStatus();

    stream <<  "Droid '" << d2.getId() << "' " << *status << ", " << d2.getEnergy();
    return (stream);
}