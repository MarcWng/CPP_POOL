/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** test.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Woody.hpp"
#include "../Buzz.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Toy, basic_toy)
{
    const Toy t;

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
    t.setName("bla");
    t.setAscii("tests/woody.txt");
    cr_expect(t.getName().compare("bla") == 0);
    cr_expect(t.getAscii().compare("this\n"\
                                    "is\n"  \
                                    "woody\n"\
                                    "picture") == 0);

}

Test(operator, ope)
{
    Toy t(Toy::ALIEN, "toto", "tests/test.txt");
    Toy t1(t);
    Toy t2 = t;

    cr_expect(t1.getType() == Toy::ALIEN);
    cr_expect(t1.getName().compare("toto") == 0);
    cr_expect(t1.getAscii().compare("this\nis\na\npicture") == true);
    cr_expect(t2.getName().compare("toto") == 0);
    cr_expect(t2.getAscii().compare("this\nis\na\npicture") == true);
}