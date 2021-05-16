/*
** EPITECH PROJECT, 2021
** menu_2021
** File description:
** main.cpp.c
*/

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../include/sfml.hpp"
#include "../srcNCURSES/win.hpp"
#include <cstring>

#define info(base, name) base.findModule(name)

int main(int ac, char **av)
{
    InfoManager manager;
    manager.addModule(new Hostname);
    manager.addModule(new OS_name);
    manager.addModule(new Time);
    manager.addModule(new RAM);
    manager.addModule(new Network);
    if (ac == 2 && !strcmp("graphical", av[1])) {
        VSFML::start(manager);
        return (0);
    } if (ac == 2 && !strcmp("text", av[1])) {
        start(manager.getModules().size() + manager.getCpuNb());
        return (0);
    }
    int mode;
    sf::RenderWindow window(sf::VideoMode(800, 600), "MENU window");
    sf::Texture texture;
    window.setFramerateLimit(60);
    if (!texture.loadFromFile("srcMenu/MENU_FOND.png"))
        return EXIT_FAILURE;
    std::vector<sf::RectangleShape> rects;
    sf::Sprite sprite(texture);
    sf::Font font;
    if (!font.loadFromFile("srcMenu/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text textNcurse("NCURSE", font, 40);
    textNcurse.setPosition(100, 210);
    sf::RectangleShape rectNcurse(sf::Vector2f(260.0f,120.0f));
    textNcurse.setFillColor(sf::Color::White);
    rectNcurse.setFillColor(sf::Color::Black);
    rectNcurse.setPosition(100,240);
    rectNcurse.setOrigin(64.0f,64.0f);

    sf::Text textSFML("SFML", font, 40);
    textSFML.setPosition(100, 410);
    sf::RectangleShape rectSFML(sf::Vector2f(260.0f,120.0f));
    textSFML.setFillColor(sf::Color::White);
    rectSFML.setFillColor(sf::Color::Black);
    rectSFML.setPosition(100,440);
    rectSFML.setOrigin(64.0f,64.0f);

    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseMoved:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (rectNcurse.getGlobalBounds().contains(mousePosF))
                        textNcurse.setFillColor(sf::Color::Blue);
                    else
                        textNcurse.setFillColor(sf::Color::White);
                    if (rectSFML.getGlobalBounds().contains(mousePosF))
                        textSFML.setFillColor(sf::Color::Blue);
                    else
                        textSFML.setFillColor(sf::Color::White);
                }
                    break;
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (rectNcurse.getGlobalBounds().contains(mousePosF))
                    {
                        mode = 1;
                        window.close();
                    }
                    if (rectSFML.getGlobalBounds().contains(mousePosF))
                    {
                        mode = 2;
                        window.close();
                    }
                }
                    break;
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(rectNcurse);
        window.draw(textNcurse);
        window.draw(rectSFML);
        window.draw(textSFML);
        window.display();
    }
    if (mode == 1)
        start(manager.getModules().size() + manager.getCpuNb());
    if (mode == 2)
        VSFML::start(manager);
    return EXIT_SUCCESS;
}
