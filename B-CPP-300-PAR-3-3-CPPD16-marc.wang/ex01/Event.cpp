/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** Event.cpp
*/

#include "Event.hpp"

Event::Event() :
    _task(""), _time(0)
{
}

Event::Event(unsigned int time, const std::string &event) :
    _task(event), _time(time)
{
}
Event::Event(const Event &other)
{
    this->_task = other._task;
    this->_time = other._time;
}

Event &Event::operator=(const Event &rhs)
{
    this->_task = rhs._task;
    this->_time = rhs._time;
    return *this;
}

Event::~Event()
{
}

unsigned int Event::getTime() const
{
    return this->_time;
}
const std::string &Event::getEvent() const
{
    return this->_task;
}
void Event::setTime(unsigned int time)
{
    this->_time = time;
}

void Event::setEvent(const std::string &event)
{
    this->_task = event;
}