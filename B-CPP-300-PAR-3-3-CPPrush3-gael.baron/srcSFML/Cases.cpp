/*
** EPITECH PROJECT, 2021
** Cases
** File description:
** functions
*/

#include "../include/sfml.hpp"
#include <iostream>

VSFML::Case::Case(sf::Texture *texture, int nb, std::string data): _nb(nb)
{
    int length = nb % 4;
    sf::Vector2f position;

    this->_isRAM = false;
    this->_isNetwork = false;
    this->_cpuValue = 0.0;
    this->_isCpu = false;
    this->_data.setString(data);
    this->_last = false;
    if (length != 0)
        length = 1;
    this->_font.loadFromFile("res/font.otf");
    this->_sprite.setTexture(*texture);
    this->_sprite.setScale(0.5, 0.5);
    this->_pos = {static_cast<float>(360 * (nb / 4)),
                  static_cast<float>(240 * (nb % 4))};
    this->_sprite.setPosition(_pos);
    this->_cross.setString("x");
    this->_cross.setFont(_font);
    this->_cross.setCharacterSize(30);
    this->_cross.setFillColor(sf::Color::Black);
    this->_data.setFont(_font);
    this->_data.setCharacterSize(15);
    this->_data.setFillColor(sf::Color::Black);
    position = _pos;
    position.y += 50;
    position.x += 15;
    this->_data.setPosition(position);
    position.x -= 15;
    position.y -= 50;
    position.x += 335;
    this->_cross.setPosition(position);
    this->_barSizeMax = 350.0;
}

VSFML::Case::~Case()
{
}

VSFML::Cases::Cases(int y, int x)
{
    sf::Vector2f pos = {static_cast<float>(y), static_cast<float>(x)};

    this->_genericTexture.loadFromFile("res/casesTexture.png");
    this->_buttonPos = pos;
    this->_font;
    this->_font.loadFromFile("res/font.otf");
    this->_buttonTop.setString("       ");
    this->_buttonTop.setFont(_font);
    this->_buttonTop.setCharacterSize(30);
    this->_buttonTop.setFillColor(sf::Color::White);
    this->_buttonTop.setPosition(pos);
    this->_buttonTop.setStyle(sf::Text::Underlined);
    pos.y += 29;
    this->_buttonMid.setString("| + |");
    this->_buttonMid.setFont(_font);
    this->_buttonMid.setCharacterSize(30);
    this->_buttonMid.setFillColor(sf::Color::White);
    this->_buttonMid.setPosition(pos);
    this->_buttonLow.setString("       ");
    this->_buttonLow.setFont(_font);
    this->_buttonLow.setCharacterSize(30);
    this->_buttonLow.setFillColor(sf::Color::White);
    this->_buttonLow.setPosition(pos);
    this->_buttonLow.setStyle(sf::Text::Underlined);
}

VSFML::Cases::~Cases()
{
}

void VSFML::Cases::addCase(Case &newCase)
{
    if (newCase._last == true)
        this->_list.push_back(newCase);
    else
        this->_list.insert(this->_list.begin(), newCase);
}

void VSFML::Cases::addCaseCpu(Case &newCase, InfoManager &manager, std::string str)
{
    sf::Vector2f position = newCase._pos;
    sf::Vector2f barSize = { 5, newCase._barSizeMax};

    if (newCase._last == true)
        this->_list.push_back(newCase);
    else {
        newCase._isCpu = true;
        newCase._bar.setSize(barSize);
        position.y += 100;
        position.x += 50;
        newCase._data.setString(str);
        newCase._cpuValue = manager.findCoreValue(str);
        newCase._bar.setPosition(position);
        newCase._bar.setOutlineColor(sf::Color::Yellow);
        newCase._bar.setOutlineThickness(3);
        newCase._bar.setFillColor(sf::Color::Yellow);
        newCase._barValue.setString(std::to_string(manager.findCoreValue(str)));
        newCase._barValue.setFont(newCase._font);
        newCase._barValue.setCharacterSize(30);
        newCase._barValue.setFillColor(sf::Color::Black);
        this->_list.insert(this->_list.begin(), newCase);
    }
}
