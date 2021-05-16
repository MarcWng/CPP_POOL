/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** test.cpp
*/

#include "../Paladin.hpp"
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Hunter.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Character, normal_creation, .init = redirect_all_std)
{
    Character bob("bob", 32);

    cr_assert_stdout_eq_str("bob Created\n");
}

Test(getName, name, .init = redirect_all_std)
{
    Character bob("bob", 32);

    cr_assert_str_eq(bob.getName().c_str(), "bob");
}

Test(getLvl, getlvl, .init = redirect_all_std)
{
    Character bob("bob", 32);
    
    cr_expect(bob.getLvl() == 32);
}

Test(getPv, PV, .init = redirect_all_std)
{
    Character bob("bob", 32);
    
    bob.TakeDamage(123);
    cr_expect(bob.getPv() == 0);
}

Test(CloseAttack, pow, .init = redirect_all_std)
{
    Character bob("bob", 32);

    cr_expect(bob.CloseAttack() == 15);
    cr_assert_stdout_eq_str("bob Created\nbob strikes with a wooden stick\n");
}

Test(getPower, pow, .init = redirect_all_std)
{
    Character bob("bob", 32);

    cr_expect(bob.getPower() == 100);
    bob.CloseAttack();
    cr_expect(bob.getPower() == 90);
}

Test(Paladin, pal_close, .init = redirect_all_std)
{
    Paladin pal("boudin", 32);

    cr_expect(pal.CloseAttack() == 29);
    cr_expect(pal.getPower() == 70);
    cr_expect_stdout_eq_str("boudin Created\nI'm boudin KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n" \
    "boudin teleported\n"   \
    "boudin enters in the order\n"  \
    "the light falls on boudin\nboudin strikes with his hammer\n");
}

Test(Paladin, pal_range, .init = redirect_all_std)
{
    Paladin pal("boudin", 32);
    
    cr_expect(pal.RangeAttack() == 30);
    cr_expect(pal.getPower() == 75);
    cr_expect_stdout_eq_str("boudin Created\nI'm boudin KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n" \
    "boudin teleported\n"   \
    "boudin enters in the order\n"  \
    "the light falls on boudin\nboudin launches a fire ball\n");
}

Test(Paladin, pal_functions, .init = redirect_all_std)
{
    Paladin pal("boudin", 32);

    cr_expect(pal.RangeAttack() == 30);
    cr_expect(pal.RangeAttack() == 30);
    cr_expect(pal.RangeAttack() == 30);
    cr_expect(pal.RangeAttack() == 30);
    cr_expect(pal.RangeAttack() == 0);
    cr_expect(pal.CloseAttack() == 0);
    pal.Heal();
    cr_expect(pal.Intercept() == 0);
    pal.RestorePower();
    cr_expect(pal.getPower() == 100);
    pal.Intercept();
    cr_expect(pal.Range == Character::CLOSE);
    pal.Range = Character::RANGE;
    cr_expect(pal.CloseAttack() == 0);
    cr_expect_stdout_eq_str("boudin Created\nI'm boudin KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n" \
    "boudin teleported\n"   \
    "boudin enters in the order\n"  \
    "the light falls on boudin\n"\
    "boudin launches a fire ball\n"\
    "boudin launches a fire ball\n"\
    "boudin launches a fire ball\nboudin launches a fire ball\nboudin out of power\nboudin out of power\nboudin out of power\nboudin eats\n");
}

Test(Priest, priest_functions, .init = redirect_all_std)
{
    Priest pri("boudin", 32);
    
    cr_expect(pri.CloseAttack() == 31);
    cr_expect(pri.CloseAttack() == 0);
    pri.Range = Character::CLOSE;
    cr_expect(pri.RangeAttack() == 41);
    pri.RangeAttack();
    pri.RangeAttack();
    pri.RangeAttack();
    cr_expect(pri.RangeAttack() == 0);
    pri.Range = Character::CLOSE;
    pri.CloseAttack();
    pri.Range = Character::CLOSE;
    cr_expect(pri.CloseAttack() == 0);
    pri.TakeDamage(4);
    cr_assert(pri.getPv() == 96);
    pri.RestorePower();
    cr_assert(pri.getPower() == 97);
    pri.Heal();
    cr_assert(pri.getPv() == 100);
    pri.TakeDamage(99);
    pri.Heal();
    cr_assert(pri.getPv() == 71);
    cr_assert_stdout_eq_str("boudin Created\nboudin teleported\nboudin enters in the order\n"   \
    "boudin uses a spirit explosion\nboudin launches a fire ball\nboudin launches a fire ball\n"    \
    "boudin launches a fire ball\nboudin out of power\nboudin out of power\nboudin uses a spirit explosion\n"   \
    "boudin out of power\nboudin takes 4 damage\nboudin takes a mana potion\nboudin casts a little heal spell\n" \
    "boudin takes 99 damage\nboudin casts a little heal spell\n");
}

Test(Hunter, hunter_functions, .init = redirect_all_std)
{
    Hunter hunt("boudin", 12);

    hunt.RangeAttack();
        hunt.RangeAttack();
    hunt.RangeAttack();
    hunt.RangeAttack();
    cr_assert(hunt.RangeAttack() == 0);
    hunt.RestorePower();
    cr_expect(hunt.getPower() == 100);
    cr_expect_stdout_eq_str("boudin Created\nI'm boudin KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nboudin is born from a tree\n"   \
        "boudin uses his bow\nboudin uses his bow\nboudin uses his bow\nboudin uses his bow\nboudin out of power\nboudin meditates\n");

}

Test(Warrior, warrior_function, .init = redirect_all_std)
{
    Warrior war("boudin", 53);

    war.CloseAttack();
    war.CloseAttack();
    war.CloseAttack();
    war.Range = Character::RANGE;
    cr_expect(war.RangeAttack() == 0);
    war.Range = Character::RANGE;
    cr_expect(war.RangeAttack() == 0);
    cr_assert_stdout_eq_str("boudin Created\nI'm boudin KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nboudin strikes with his hammer\n"\
    "boudin strikes with his hammer\nboudin strikes with his hammer\nboudin intercepts\nboudin out of power\n");
}

Test(Mage, mage_functions, .init = redirect_all_std)
{
    Mage mag("boudin", 41);

    cr_assert(mag.CloseAttack() == 0);
    mag.RangeAttack();
    mag.RangeAttack();
    mag.RangeAttack();
    mag.Range = Character::CLOSE;
    mag.CloseAttack();
    mag.Range = Character::CLOSE;
    mag.CloseAttack();
    mag.RestorePower();
    mag.RestorePower();
    cr_assert_stdout_eq_str("boudin Created\n"    \
    "boudin teleported\n" \
    "boudin blinks\n" \
    "boudin launches a fire ball\n"   \
    "boudin launches a fire ball\n"   \
    "boudin launches a fire ball\n"   \
    "boudin blinks\n" \
    "boudin out of power\n"   \
    "boudin takes a mana potion\n"    \
    "boudin takes a mana potion\n");
}

Test(Character, Base_functions, .init = redirect_all_std)
{
    Character gayel("gayle", 12);

    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.CloseAttack();
    gayel.Range = Character::RANGE;
    gayel.RangeAttack();
    gayel.Heal();
    gayel.TakeDamage(51);
    gayel.Heal();
    gayel.Range = Character::RANGE;
    cr_expect(gayel.CloseAttack() == 0);
    gayel.RestorePower();
    gayel.RangeAttack();
    gayel.TakeDamage(99);
    cr_assert_stdout_eq_str("gayle Created\n"   \
    "gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle strikes with a wooden stick\n" \
"gayle out of power\n"    \
"gayle out of power\n"    \
"gayle takes a potion\n"  \
"gayle takes 51 damage\n" \
"gayle takes a potion\n"  \
"gayle eats\n"    \
"gayle tosses a stone\n"  \
"gayle takes 99 damage\n" \
"gayle out of combat\n");
}