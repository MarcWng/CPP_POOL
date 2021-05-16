/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** EventManager.hpp
*/

#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"
#include <vector>
#include <list>

class EventManager
{
    public:
    EventManager();
    EventManager(EventManager const &other);
    EventManager &operator=(EventManager const &rhs);
    ~EventManager();
    void addEvent(const Event &e);
    void removeEventsAt(unsigned int time);
    void dumpEvents()const;
    void dumpEventAt(unsigned int time) const;
    void addTime(unsigned int time);
    void addEventList(const std::list<Event> &events);

    private:
    std::list<Event> _event;
    unsigned int _actualTime;
};

#endif