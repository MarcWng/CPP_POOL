/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD08-marc.wang
** File description:
** Droid.hpp
*/

#ifndef DROID_HPP
#define DROID_HPP

#include <string>
#include <iostream>
#include "DroidMemory.hpp"

class Droid
{
private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
    DroidMemory *BattleData;
public:
    Droid(std::string serial);
    Droid(const Droid &d2);
    ~Droid();

    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    DroidMemory *getBattleData();

    void setId(std::string Id);
    void setEnergy(size_t Energy);
    void setStatus(std::string *status);
    void setBattleData(DroidMemory* b_data);
    bool operator==(const Droid &d2) const;
    Droid &operator<<(size_t e2);
    bool operator!=(const Droid &d2) const;
    Droid &operator=(const Droid &d2);
    bool operator()(std::string *task, size_t exp);
};
std::ostream &operator<<(std::ostream &stream, const Droid &d2);

#endif