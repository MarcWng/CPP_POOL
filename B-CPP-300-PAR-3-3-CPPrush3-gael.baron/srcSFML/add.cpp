/*
** EPITECH PROJECT, 2021
** add
** File description:
** functions
*/

#include "../include/sfml.hpp"

#define info(base, name) base.findModule(name)

void VSFML::refreshCore(InfoManager manager, VSFML::Cases *cases)
{
    sf::Vector2f size;
    sf::Vector2f position;
    int i = 0;

        for (auto it = cases->_list.begin(); it != cases->_list.end(); it++) {
            if (it->_isCpu) {
                position = it->_pos;
                it->_cpuValue = manager.findCoreValue(it->_data.getString());
                size.x = 350 * (it->_cpuValue / 100);
                it->_bar.setSize(size);
                position.x += 50;
                position.y += 100;
                it->_bar.setPosition(position);
                it->_barValue.setString(std::to_string(manager.findCoreValue(it->_data.getString())));
                it->_barValue.setPosition(position);
            }
        }
}

void VSFML::closureSec(sf::RenderWindow *window, sf::Event *ev,
                       VSFML::Cases *cases, sf::Vector2i mousePos)
{
    if (mousePos.x >= cases->_buttonPos.x&& mousePos.x <= cases->_buttonPos.x + 60
        && mousePos.y >= cases->_buttonPos.y + 15 && mousePos.y <= cases->_buttonPos.y + 60) {
        cases->_buttonLow.setFillColor(sf::Color::Green);
        cases->_buttonMid.setFillColor(sf::Color::Green);
        cases->_buttonTop.setFillColor(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            cases->addCase(*new VSFML::Case(&cases->_genericTexture, cases->_list.size(), ""));
    } else {
        cases->_buttonLow.setFillColor(sf::Color::White);
        cases->_buttonMid.setFillColor(sf::Color::White);
        cases->_buttonTop.setFillColor(sf::Color::White);
    }
}

void VSFML::drawing(sf::RenderWindow *window, VSFML::Cases cases, InfoManager manager)
{
    for (auto it = cases._list.begin(); it != cases._list.end(); it++) {
        if (it->_isRAM) {
            manager.resetRAM();
            manager.addModule(new RAM);
            it->_data.setString(info(manager, "RAM"));
        } if (it->_isNetwork) {
            manager.resetNetwork();
            manager.addModule(new Network);
            it->_data.setString(info(manager, "Network"));
        }
        window->draw(it->_sprite);
        window->draw(it->_data);
        window->draw(it->_cross);
        if (it->_isCpu) {
            window->draw(it->_bar);
            window->draw(it->_barValue);
        }
    }
    window->draw(cases._buttonTop);
    window->draw(cases._buttonMid);
    window->draw(cases._buttonLow);
    window->display();
    window->clear(sf::Color::Black);
}
