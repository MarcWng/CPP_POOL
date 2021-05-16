/*
** EPITECH PROJECT, 2021
** Objects
** File description:
** functions
*/

#include "Objects.hpp"

Object::Object(std::string const title): _title(title)
{
}

Object::Object(Object *obj):_title(obj->getTitle())
{
}

Object::~Object(void)
{
}

std::string const Object::getTitle(void) const
{
    return (this->_title);
}

Toy::Toy(std::string const title): Object(title)
{
}

Toy::~Toy(void)
{
}

std::ostream &operator<<(std::ostream &out, const Object &obj)
{
    out << obj.getTitle();
    return (out);
}
