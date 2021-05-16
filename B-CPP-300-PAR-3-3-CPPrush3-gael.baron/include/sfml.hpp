/*
** EPITECH PROJECT, 2021
** SFML
** File description:
** header
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../src/modules/Hostname.hpp"
#include "../src/modules/IMonitorModule.hpp"
#include "../src/modules/InfoManager.hpp"
#include <exception>
#include "../src/modules/OS_name.hpp"
#include "../src/modules/Time.hpp"
#include "../src/modules/RAM.hpp"
#include "../src/modules/Network.hpp"

namespace VSFML
{
    class Needed
    {
    private:
        int _nbElem;
    public:
        Needed(int nbElem):_nbElem(nbElem){};
        ~Needed() {};
        int getNbElem() {return (this->_nbElem);};
    };

    class Case
    {
    public:
        sf::Text _data;
        sf::Sprite _sprite;
        sf::Vector2f _pos;
        int _nb;
        sf::Font _font;
        sf::Text _cross;
        bool _last;
        sf::RectangleShape _bar;
        sf::Text _barValue;
        bool _isCpu;
        float _barSizeMax;
        float _cpuValue;
        bool _isRAM;
        bool _isNetwork;

        Case(sf::Texture *texture, int nb, std::string data);
        ~Case();
        int getNb(){return (this->_nb);};
    };

    class Cases {
    public:
        std::vector<Case> _list;
        sf::Texture _genericTexture;
        sf::Font _font;
        sf::Vector2f _buttonPos;
        sf::Text _buttonTop;
        sf::Text _buttonMid;
        sf::Text _buttonLow;
        Cases(int y, int x);
        ~Cases();
        void addCase(Case &newCase);
        void addCaseCpu(Case &newCase, InfoManager &manager, std::string name);
    };
/*    main_sfml.cpp   */
    int start(InfoManager manager);
    void mainLoop(sf::RenderWindow *window, VSFML::Cases cases, InfoManager manager);
    void eventLoop(sf::RenderWindow *window, sf::Event *ev, VSFML::Cases *cases);
    void closure(sf::RenderWindow *window, sf::Event *ev, VSFML::Cases *cases);
    void replaceCases(sf::RenderWindow *window, VSFML::Cases *cases);

/*    add.cpp    */
    void closureSec(sf::RenderWindow *window, sf::Event *ev,
                    VSFML::Cases *cases, sf::Vector2i mousePos);
    void drawing(sf::RenderWindow *window, VSFML::Cases cases, InfoManager manager);
    void refreshCore(InfoManager manager, VSFML::Cases *cases);
}

#endif
