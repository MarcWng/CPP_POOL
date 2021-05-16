/*
** EPITECH PROJECT, 2021
** main_sfml
** File description:
** SFML main funcitons
*/

#include "../include/sfml.hpp"
#include <iostream>

#define info(base, name) base.findModule(name)

void VSFML::replaceCases(sf::RenderWindow *window, VSFML::Cases *cases)
{
    int y = 0;
    int x = 0;
    sf::Vector2f crossPos;

    for (auto it = cases->_list.begin(); it != cases->_list.end(); it++) {
        if (it->_pos.x >= 0) {
            if (it->_pos.x != x || it->_pos.y != y) {
                it->_pos.x = x;
                it->_pos.y = y;
                it->_sprite.setPosition(it->_pos);
                crossPos = it->_pos;
                crossPos.y += 50;
                crossPos.x += 15;
                it->_data.setPosition(crossPos);
                crossPos.x -= 15;
                crossPos.y -= 50;
                crossPos.x += 335;
                it->_cross.setPosition(crossPos);
            }
            y += 240;
            if (y >= 920) {
                y = 0;
                x += 360;
            }
        }
    }
}

void VSFML::closure(sf::RenderWindow *window, sf::Event *ev, VSFML::Cases *cases)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f crossPos;

    for (auto it = cases->_list.begin(); it != cases->_list.end(); it++) {
        crossPos = it->_pos;
        crossPos.x += 335;
        if (mousePos.x >= crossPos.x && mousePos.x <= crossPos.x + 30
            && mousePos.y >= crossPos.y && mousePos.y <= crossPos.y + 30) {
            it->_cross.setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                cases->_list.erase(it);
        } else
            it->_cross.setFillColor(sf::Color::Black);
    }
    VSFML::closureSec(window, ev, cases, mousePos);
}

void VSFML::eventLoop(sf::RenderWindow *window, sf::Event *ev, VSFML::Cases *cases)
{
    while (window->pollEvent(*ev)) {
        if (ev->type == sf::Event::Closed ||
            (ev->type == sf::Event::KeyPressed && ev->key.code == sf::Keyboard::Escape))
            window->close();
        closure(window, ev, cases);
    }
}

void VSFML::mainLoop(sf::RenderWindow *window, VSFML::Cases cases, InfoManager manager)
{
    int close = false;

    while (window->isOpen()) {
        manager.resetCores();
        manager.setAllCore();
        refreshCore(manager, &cases);
        sf::Event ev;
        VSFML::eventLoop(window, &ev, &cases);
        replaceCases(window, &cases);
        VSFML::drawing(window, cases, manager);
    }
}

int VSFML::start(InfoManager manager)
{
    Needed nd(manager.getModules().size() + manager.getCpuNb());
    sf::Texture stopperTexture;
    int length = (nd.getNbElem() % 4);
    if (length % 4 != 0)
        length = 1;
    sf::Vector2f out = { -1000, -1000};
    sf::RenderWindow window(sf::VideoMode(360 * (length + (nd.getNbElem() / 4)),
                            240 * ((nd.getNbElem() / 4) + nd.getNbElem()) + 50), "MyGKrellm");
    VSFML::Cases cases(window.getSize().x / 2 - 25,
                       window.getSize().y - 75);
    int id = 0;
    window.setFramerateLimit(60);
    window.setPosition({0, 0});

    stopperTexture.loadFromFile("res/empty.png");
    cases.addCase(*new Case(&cases._genericTexture, id, info(manager, "Hostname")));
    cases.addCase(*new Case(&cases._genericTexture, id, info(manager, "OS")));
    cases.addCase(*new Case(&cases._genericTexture, id, info(manager, "Time")));
    cases.addCase(*new Case(&cases._genericTexture, id, info(manager, "RAM")));
    cases._list.begin()->_isRAM = true;
    cases.addCase(*new Case(&cases._genericTexture, id, info(manager, "Network")));
    cases._list.begin()->_isNetwork = true;
    manager.setAllCore();
    cases.addCaseCpu(*new Case(&cases._genericTexture, id, manager.findCore("cpu")),
                     manager, "cpu");
    for (int i = 0; i < manager.getCpuNb() - 1; i++) {
        cases.addCaseCpu(*new Case(&cases._genericTexture, id,
                                   manager.findCore("cpu" + std::to_string(i))), manager,
                         "cpu" + std::to_string(i));
    }
    VSFML::Case special(&stopperTexture, nd.getNbElem(), "");
    special._last = true;
    cases.addCase(special);
    (cases._list.end() - 1)->_sprite.setPosition(out);
    (cases._list.end() - 1)->_cross.setPosition(out);
    (cases._list.end() - 1)->_pos = out;
    VSFML::mainLoop(&window, cases, manager);
    return (0);
}
