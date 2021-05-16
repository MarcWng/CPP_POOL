/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** test.cpp
*/

#include "../Objects.hpp"
#include "../Toys.hpp"
#include "../IConvoyerBelt.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Toy, toy_creation)
{
    Object **obj = new Object*;
    obj[0] = new LittlePony("happy pony");
    obj[1] = new Teddy("cuddles");
    cr_assert_str_eq(obj[0]->getTitle().c_str(), "happy pony");
    cr_assert_str_eq(obj[1]->getTitle().c_str(), "cuddles");
}

Test(isTaken, take_toy, .init = redirect_all_std)
{
    Teddy ted("Ted");
    LittlePony pony("Pony");

    ted.isTaken();
    pony.isTaken();
    cr_assert_stdout_eq_str("gra hu\nyo man\n");
}

Test(Wrap, wrap_system, .init = redirect_all_std)
{
    Object **obj = new Object*;

    obj[0] = new Teddy("cuddles");
    obj[1] = new Box();
    obj[2] = new GiftPaper();

    ((Box*)obj[1])->openMe();
    ((Box*)obj[1])->wrapMeThat(obj[0]);
    ((GiftPaper*)obj[2])->wrapMeThat(obj[1]);
    cr_expect(((GiftPaper*)obj[2])->openMe() == ((Box*)obj[1]));
    cr_expect(((Box*)obj[1])->openMe() == obj[0]);
    cr_assert_stdout_eq_str("whistles while working\n"   \
                            "tuuuut tuuut tuut\n"    \
                            "whistles while working\n");
}

Test(Object, overload, .init = redirect_all_std)
{
    Object obj("object");

    std::cout << obj << std::endl;
    cr_assert_stdout_eq_str("object\n");
}

Test(close_me, close_box, .init = redirect_all_std)
{
    Object **obj = new Object*;

    obj[0] = new Teddy("cuddles");
    obj[1] = new Box();

    ((Box*)obj[1])->wrapMeThat(obj[0]);
    cr_expect(((Box*)obj[1])->openMe() == nullptr);
    ((Box*)obj[1])->closeMe();
    ((Box*)obj[1])->wrapMeThat(obj[0]);
    cr_expect(((Box*)obj[1])->openMe() == nullptr);
}

Test(take, papa_convoyer_take_and_put)
{
    PapaXmasConveyorBelt *conv = (PapaXmasConveyorBelt*)createConveyorBelt();
    Object *obj = new Toy("Ted");

    conv->put(obj);

    cr_expect_not(conv == NULL);
    cr_expect(conv->getElem()->getTitle().compare("Ted") == 0);
}