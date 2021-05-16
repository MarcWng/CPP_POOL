/*
** EPITECH PROJECT, 2021
** rush 3 ncurses part
** File description:
** win.cpp
*/

#include "win.hpp"
#include <cstdlib>
#include "../src/modules/IMonitorModule.hpp"
#include "../src/modules/InfoManager.hpp"
#include "../src/modules/Hostname.hpp"
#include "../src/modules/OS_name.hpp"
#include "../src/modules/Time.hpp"
#include "../src/modules/RAM.hpp"

#define info(base, name) base.findModule(name)

win::win(int _lines_tot, int _cols_tot, int _pos_x, int _pos_y)
{
    this->lines_tot = _lines_tot;
    this->cols_tot = _cols_tot;
    this->pos_x = _pos_x;
    this->pos_y = _pos_y;
    this->msg = " ";
    this->x_max = LINES / this->lines_tot - 2;
    this->y_max = COLS / this->cols_tot - 2;
}

win::~win()
{
}

void win::setMsg(std::string _msg)
{
    this->msg = _msg;
}

const std::string win::getMsg() const
{
    return (this->msg);
}

const int win::getx() const
{
    return (this->pos_x);
}

const int win::gety() const
{
    return (this->pos_y);
}

void win::resize_win()
{
    int x = 0;
    int y = 0;

    if (this->pos_x != 0)
        x = LINES / this->lines_tot * this->pos_x;
    if (this->pos_y != 0)
        y = COLS / this->cols_tot * this->pos_y;

    this->dis = subwin(stdscr, LINES / this->lines_tot, COLS / this->cols_tot, x, y);

    box(this->dis, ACS_VLINE, ACS_HLINE);
}

void win::print_msg(float cord_x, float cord_y, std::string msg)
{
    this->setMsg("                                  ");
    if (!msg.empty())
        this->setMsg(msg);
    mvwprintw(this->dis, cord_x, cord_y, this->msg.c_str());
    wrefresh(this->dis);
}

void win::fill_v()
{
    for (int y = 1; y != this->y_max + 1; y++)
        for (int x = 1; x != this->x_max + 1; x++)
            mvwprintw(this->dis, x, y, "V");
    wrefresh(this->dis);
}

void win::fill_space()
{
    for (int y = 1; y != this->y_max + 1; y++)
        for (int x = 1; x != this->x_max + 1; x++)
            mvwprintw(this->dis, x, y, " ");
    wrefresh(this->dis);
}

void select_case(int cord_x, int cord_y, std::vector<win> vec, int stat)
{
    for (std::vector<win>::iterator it = vec.begin(); it != vec.end(); it++) {
        if (it->getx() == cord_x && it->gety() == cord_y)
            if (stat == 0)
                it->fill_v();
            else
                it->fill_space();
    }
}

void print(float cord_x, float cord_y, std::vector<win> vec, int num_case, std::string msg)
{
    int i = 0;

    for (std::vector<win>::iterator it = vec.begin(); it != vec.end(); it++) {
        if (i == num_case)
            it->print_msg(cord_x, cord_y, msg);
        i++;
    }
}

void print_all_case(std::vector<win> vec, std::vector<std::string> data)
{
    std::vector<std::string>::iterator its = data.begin();

    for (std::vector<win>::iterator it = vec.begin(); it != vec.end(); it++, its++)
        if (its < data.end())
            it->print_msg(1, 1, *its);
        else
            it->print_msg(1, 1, " ");
}


void fill_vec(int lines_tot, int cols_tot, int case_tot, std::vector<win> *vec)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i != case_tot; i++, x++) {
        if (x == 4) {
            x = 0;
            y += 1;
        }
        add_tab(lines_tot, cols_tot, x, y, vec);
    }
}

void create_vec(int nb_case, std::vector<win> *vec)
{
    int x = 0;
    int y = 0;

    lines_and_cols(&x, &y, nb_case);
    fill_vec(x, y, nb_case, vec);
}

void fill_data(std::vector<std::string> *data)
{
    InfoManager manager;

    manager.addModule(new Hostname);
    manager.addModule(new OS_name);
    manager.addModule(new Time);
    manager.addModule(new RAM);

    data->push_back(info(manager, "Hostname"));
    data->push_back(info(manager, "OS"));
    data->push_back(info(manager, "Time"));
    data->push_back(info(manager, "RAM"));
    manager.setAllCore();
    data->push_back(manager.findCore("cpu"));
    for (int i = 0; i < manager.getCpuNb() - 1; i++)
        data->push_back(manager.findCore("cpu" + std::to_string(i)));

}

void add_tab(int lines_tot, int cols_tot, int pos_x, int pos_y, std::vector<win> *vec)
{
    win a(lines_tot, cols_tot, pos_x, pos_y);

    a.resize_win();
    vec->push_back(a);
}

void lines_and_cols(int *x, int *y, int nb_case)
{
    int tmp = 0;

    if (nb_case <= 4)
        *x = nb_case;
    else
        *x = 4;
    if (nb_case % 4 >= 1)
        *y = nb_case / 4 + 1;
    else
        *y = nb_case / 4;
}
