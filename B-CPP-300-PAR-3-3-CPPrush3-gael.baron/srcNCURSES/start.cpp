/*
** EPITECH PROJECT, 2021
**
** File description:
**
*/

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include "win.hpp"
#include <algorithm>
#include <iomanip>

int sup = 0;

void sup_case(std::vector<win> *vec, std::vector<std::string> *data, int num)
{
    int i = 0;
    num -= sup;
    std::vector<win>::iterator it = (*vec).begin();
    std::vector<std::string>::iterator its = data->begin();

    while (i != num) {
        i++;
        it++;
        its++;
    }
    vec->erase(it);
    data->erase(its);
    sup += 1;
}

int find_case(int x, int y)
{
    int i = 0;
    if (y == 0)
        return (x);
    for (int a = 0; a != y; i += 4, a++);
    return (i + x);
}

void selecter(std::vector<win> *vec, std::vector<std::string> *data, int *nb_case)
{
    int c = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    std::vector<win>::iterator it = vec->begin();

    keypad(it->dis, true);
    refresh();

    while (i == 0) {
        print_all_case(*vec, *data);
        select_case(x, y, *vec, 0);
        c = wgetch(it->dis);
        switch(c) {
        case KEY_UP:
            if (x > 0) {
                select_case(x, y, *vec, 1);
                x -= 1;
            }
            break;
        case KEY_LEFT:
            if (y > 0) {
                select_case(x, y, *vec, 1);
                y -= 1;
            }
            break;
        case KEY_DOWN:
            if (x < it->lines_tot - 1) {
                select_case(x, y, *vec, 1);
                x += 1;
            }
            break;
        case KEY_RIGHT:
            if (y < it->cols_tot - 1) {
                select_case(x, y, *vec, 1);
                y += 1;
            }
            break;
        case 32:
            select_case(x, y, *vec, 1);
            sup_case(vec, data, (find_case(x, y)));
            nb_case -= 1;
            i += 1;
            break;
        }
    }
}

int start(int nb_case)
{
    int x = 0;
    int y = 0;
    int c = 0;
    int i = 0;
    std::vector<std::string> data;
    std::vector<win> vec;
    std::vector<win>::iterator it;

    initscr();
    fill_data(&data);
    create_vec(nb_case, &vec);
    it = vec.begin();

    keypad(it->dis, true);
    refresh();
    while (1) {
        print_all_case(vec, data);
        if (i > 100)
            c = wgetch(it->dis);
        if (i > 200)
            i = 0;
        switch(c) {
        case 32:
            selecter(&vec, &data, &nb_case);
            //create_vec(nb_case, &vec);
            break;
        }
        i++;
    }
    getch();
    endwin();

    return (0);
}
