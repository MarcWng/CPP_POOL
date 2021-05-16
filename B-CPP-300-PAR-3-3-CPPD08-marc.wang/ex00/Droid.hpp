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

class Droid
{
private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
public:
    Droid(std::string serial = "");
    Droid(const Droid &d2);
    ~Droid();
    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    void setId(std::string Id);
    void setEnergy(size_t Energy);
    void setStatus(std::string *status);
    bool operator==(const Droid &d2) const;
    Droid &operator<<(size_t &e2);
    bool operator!=(const Droid &d2) const;
    Droid &operator=(Droid const &d2);
};
std::ostream &operator<<(std::ostream &stream, const Droid &d2);

#endif