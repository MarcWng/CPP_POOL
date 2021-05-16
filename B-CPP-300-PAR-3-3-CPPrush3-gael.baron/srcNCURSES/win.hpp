/*
** EPITECH PROJECT, 2021
** rush 3 ncurses part
** File description:
** win.hpp
*/

#ifndef WIN_HPP
#define WIN_HPP

#include <iostream>
#include <ncurses.h>
#include <vector>

class win {
public:
    std::string msg;
    WINDOW *dis;
    int x_max = 0;
    int y_max = 0;
    int pos_x = 0;
    int pos_y = 0;
    int cols_tot = 1;
    int lines_tot = 1;
    bool selected = false;
    win(int _lines_tot, int _cols_tot, int _pos_x, int _pos_y);
    ~win();
    void setMsg(std::string _msg);
    const int getx() const;
    const int gety() const;
    const std::string getMsg() const;
    void resize_win();
    void print_msg(float cord_x, float cord_y, std::string msg);
    void fill_v();
    void fill_space();
};

void create_vec(int nb_case, std::vector<win> *vec);
void print(float , float , std::vector<win> , int , std::string );
void print_all_case(std::vector<win> , std::vector<std::string> );
void fill_vec(int lines_tot, int cols_tot, int case_tot, std::vector<win> *vec);
void fill_data(std::vector<std::string> *data);
void add_tab(int lines_tot, int cols_tot, int pos_x, int pos_y, std::vector<win> *vec);
void lines_and_cols(int *x, int *y, int nb_case);
void select_case(int cord_x, int cord_y, std::vector<win> vec, int stat);
void fill_data(std::vector<std::string> *data);
int start(int nb_case);

#endif
