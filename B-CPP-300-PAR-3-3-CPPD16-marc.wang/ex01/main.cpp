/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD16-marc.wang
** File description:
** main.cpp
*/

#include <cstdlib>
#include <iostream>
#include "EventManager.hpp"

static std::list<Event> createTodoList()
{
    std::list <Event> todo;

    todo.push_back(Event(1, "The first event"));
    todo.push_back(Event(1, "The second event"));
    todo.push_back(Event(1, "The third event"));
    todo.push_back(Event(10, "Test Event"));
    todo.push_back(Event(10, "Test Event2"));
    return todo ;
}
static void populateEvents ( EventManager & m )
{
    m.addEvent(Event(22, "from populate"));
}
int main ()
{
    EventManager em;

    populateEvents(em);
    em.addEventList(createTodoList());
    em.dumpEvents();
    em.addTime(3);

    EventManager second(em);
    second.dumpEvents();
    return 0;
}
