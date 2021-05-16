/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** Event.hpp
*/

#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <vector>

class Event
{
    public:
    Event();
    Event(unsigned int time, const std::string &event);
    ~Event();
    Event(const Event &other);
    Event &operator=(const Event &rhs);
    unsigned int getTime() const;
    const std::string &getEvent() const;
    void setTime(unsigned int time);
    void setEvent(const std::string &event);

    private:
    std::string _task;
    int _time;
};

#endif