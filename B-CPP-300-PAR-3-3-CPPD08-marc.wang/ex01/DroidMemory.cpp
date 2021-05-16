/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD08-marc.wang
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : Exp(0), Fingerprint(random())
{
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getExp() const
{
    return this->Exp;
}
size_t DroidMemory::getFingerprint() const
{
    return this->Fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    this->Exp = exp;
}
void DroidMemory::setFingerprint(size_t fp)
{
    this->Fingerprint = fp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory const &memory)
{
    this->Exp =+ memory.Exp;
    this->Fingerprint = this->Fingerprint ^ memory.Fingerprint;
    return *this;
}

DroidMemory const &DroidMemory::operator>>(DroidMemory &memory) const
{
    memory.Exp =+ this->Exp;
    memory.Fingerprint = this->Fingerprint ^ memory.Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &memory)
{
    this->Exp =+ memory.Exp;
    this->Fingerprint = this->Fingerprint ^ memory.Fingerprint;
    return *this;

}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    this->Exp =+ exp;
    return *this;
}

DroidMemory &DroidMemory::operator+(DroidMemory const &memory) const
{
    DroidMemory *ret = new DroidMemory();
    ret->Exp =+ memory.Exp;
    return *ret;
}

DroidMemory &DroidMemory::operator+(size_t exp) const
{
    DroidMemory *ret = new DroidMemory();
    ret->Exp =+ exp;
    return *ret;
}

std::ostream &operator<<(std::ostream &stream, DroidMemory const &d2)
{
    stream <<  "Droid '" << d2.getFingerprint() << "', " << d2.getExp();
    return (stream);
}