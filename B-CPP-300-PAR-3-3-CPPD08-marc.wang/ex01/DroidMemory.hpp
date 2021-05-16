/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD08-marc.wang
** File description:
** DroidMemory.hpp
*/

#ifndef DROIDMEMORY_HPP
#define DROIDMEMORY_HPP

#include <iostream>

class DroidMemory
{
private:
    size_t Exp;
    size_t Fingerprint;
public:
    DroidMemory();
    ~DroidMemory();
    size_t getExp() const;
    size_t getFingerprint() const;
    void setExp(size_t exp);
    void setFingerprint(size_t fp);
    DroidMemory &operator<<(DroidMemory const &memory);
    DroidMemory const &operator>>(DroidMemory &memory) const;
    DroidMemory &operator+=(DroidMemory const &memory);
    DroidMemory &operator+=(size_t exp);
    DroidMemory &operator+(DroidMemory const &memory) const;
    DroidMemory &operator+(size_t exp) const;
};
std::ostream &operator<<(std::ostream &stream, const DroidMemory &d2);

#endif