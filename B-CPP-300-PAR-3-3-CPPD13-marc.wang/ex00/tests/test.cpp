/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** test.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Toy.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Toy, basic_toy)
{
    Toy t;

    cr_expect(t.getType() == Toy::BASIC_TOY);
    cr_expect(t.getName().compare("toy") == 0);
    cr_expect(t.getAscii().empty() == true);
}

Test(Picture, basic_pic)
{
    Picture p;

    cr_expect(p.data.empty() == true);
    cr_expect(p.getPictureFromFile("tests/test.txt") == true);
    cr_expect(p.data.compare("this\nis\na\npicture") == true);
}

Test(Toy, toy_from_file)
{
    Toy t(Toy::ALIEN, "toto", "tests/test.txt");

    cr_expect(t.getType() == Toy::ALIEN);
    cr_expect(t.getName().compare("toto") == 0);
    cr_expect(t.getAscii().compare("this\nis\na\npicture") == true);
}