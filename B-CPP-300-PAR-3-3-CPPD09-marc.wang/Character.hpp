/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Character.hpp
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>



class Character
{
    public:
    typedef enum {
        RANGE,
        CLOSE
    }AttackRange;

    Character(const std::string &name, int level);
    ~Character();
    const std::string &_name;
    int _lvl;
    AttackRange Range;
    const std::string &getName() const;
    int getLvl() const;
    int CloseAttack();
    void Heal();
    int RangeAttack();
    void RestorePower();
    void TakeDamage(int damage);
    int getPv() const;
    int getPower() const;

    protected:
    int _pv;
    int _power;
    int _stamina;
    int _spirit;
    int _agility;
    int _strength;
    int _intelligence;
    std::string _class;
    std::string _race;
};



#endif