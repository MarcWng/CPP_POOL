/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** EventManager.cpp
*/

#include "EventManager.hpp"
#include <algorithm>

EventManager::EventManager() :
    _event(24), _actualTime(0)
{
}

EventManager::EventManager(EventManager const &other)
{
    this->_event = other._event;
    this->_actualTime = other._actualTime;
}

EventManager &EventManager::operator=(EventManager const &rhs)
{
    this->_event = rhs._event;
    this->_actualTime = rhs._actualTime;
    return *this;
}

EventManager::~EventManager()
{
}

bool sortTime(const Event &evt1, const Event &evt2)
{
    if (evt1.getTime() <= evt2.getTime())
        return(true);
    return(false);
}

bool sortEvt(const Event &a, const Event &b)
{
    return (a.getTime() <= b.getTime());
}

void EventManager::addEvent(const Event &e)
{
    bool sort_bool = true;
    int time = e.getTime();
    std::string event = e.getEvent();

    if (e.getEvent().empty() == true)
        return;
    if (this->_actualTime > time)
        return;
    if (this->_event.back().getTime() == e.getTime())
        sort_bool = false;
    this->_event.push_back(e);
    if (sort_bool == true)
        this->_event.sort(sortEvt);
}

void EventManager::removeEventsAt(unsigned int time)
{
    for (std::list<Event>::iterator it = this->_event.begin(); it != this->_event.end(); ++it) {
        if (it->getTime() == time) {
            it = this->_event.erase(it);
            it--;
        }
    }
}

void EventManager::dumpEvents() const
{
    for(const Event &e : this->_event)
        if (e.getTime() > this->_actualTime)
            std::cout << e.getTime() << ": " << e.getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    if (this->_actualTime > time)
        return;
    for (const Event &e : this->_event)
        if (e.getTime() == time)
            std::cout << e.getTime() << ": " << e.getEvent() << std::endl;
}

void EventManager::addTime(unsigned int time)
{
    for (const Event &e : this->_event) {
		if (e.getTime() > this->_actualTime && e.getTime() <= this->_actualTime + time) {
			std::cout << e.getEvent() << std::endl;
            removeEventsAt(_actualTime);
		}
	}
    this->_actualTime = this->_actualTime + time;

}

void EventManager::addEventList(const std::list<Event> &events)
{
    for (const Event &e : events)
        addEvent(e);
}