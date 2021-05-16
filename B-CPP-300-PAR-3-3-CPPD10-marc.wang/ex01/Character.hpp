/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Character.hpp
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AEnemy.hpp"

class Character
{
    private:
    const std::string _name;
    int _ap;
    AWeapon *_weapon;
    public:
    Character(const std::string &name);
    ~Character();
    void recoverAP();
    void equip(AWeapon *weapon);
    void attack(AEnemy *enemy);
    const std::string getName() const;
    int getAp() const;
    AWeapon *getWeapon() const;
};

std::ostream &operator<<(std::ostream &stream, const Character &c);

#endif