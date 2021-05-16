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
    this->Energy = 50;
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

DroidMemory *Droid::getBattleData()
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
    return (this->Status == d2.Status);
}

bool Droid::operator!=(const Droid &d2) const
{
    return !(this->Status == d2.Status);
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
    this->Id = d2.Id;
    if (this->Status)
        delete this->Status;
    this->Status = new std::string(*(d2.Status));
    this->BattleData = d2.BattleData;
    return *this;
}

bool Droid::operator()(std::string *task, size_t exp)
{
    std::string *low = new std::string("Battery Low");

    if (this->Energy == 0 || this->Energy < 10) {
        this->setStatus(low);
        if (this->Energy != 0)
            this->setEnergy(0);
        return false;
    }
    if (this->BattleData->getExp() >= exp) {
        task->append(" - Completed!");
        this->Status = task;
        this->BattleData->setExp(this->BattleData->getExp() + (exp / 2));
        this->setEnergy(this->getEnergy() - 10);
        return true;
    } else {
        task->append(" - Failed!");
        this->Status = task;
        this->BattleData->setExp(this->BattleData->getExp() + exp);
        this->setEnergy(this->getEnergy() - 10);
        return false;
    }
    return false;
}


std::ostream &operator<<(std::ostream &stream, const Droid &d2)
{
    std::string const *status = d2.getStatus();

    stream <<  "Droid '" << d2.getId() << "' " << *status << ", " << d2.getEnergy();
    return (stream);
}