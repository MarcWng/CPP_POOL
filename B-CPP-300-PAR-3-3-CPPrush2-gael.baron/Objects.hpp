/*
** EPITECH PROJECT, 2021
** Objects
** File description:
** header
*/

#ifndef OBJECTS_HPP_
#define OBJECTS_HPP_

#include <iostream>

class Object
{
protected:
    std::string const _title;
public:
    virtual ~Object();
    Object(Object *obj);
    Object(std::string const title);
    std::string const getTitle() const;
};

class Toy: virtual public Object
{
public:
    Toy(std::string const title);
    ~Toy();
};

std::ostream &operator<<(std::ostream &out, const Object &obj);

#endif
