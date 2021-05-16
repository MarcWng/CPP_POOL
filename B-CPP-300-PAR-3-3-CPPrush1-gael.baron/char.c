/*
** EPITECH PROJECT, 2021
** int
** File description:
** functions
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char *str;
    char     c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = (char)va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (this && this->str)
        free(this->str);
}

// Create additional functions here

static char *Char_to_str(CharClass *this)
{
    int size = 1 + strlen(this->base.__name__) + 5 + 1;

    this->str = malloc(sizeof(char) * size);
    snprintf(this->str, size, "<%s (%c)>", this->base.__name__,
             this->c);
    return (this->str);
}

static CharClass *Char_add(CharClass *this, CharClass *other)
{
    Object  *p1 = new(Char, this->c + other->c);

    return ((CharClass *)p1);
}

static CharClass *Char_sub(CharClass *this, CharClass *other)
{
    Object  *p1 = new(Char, this->c);

    ((CharClass *)p1)->c = this->c - other->c;
    return (p1);
}

static CharClass *Char_mul(CharClass *this, CharClass *other)
{
    Object  *p1 = new(Char, this->c);

    ((CharClass *)p1)->c = this->c * other->c;
    return (p1);
}

static CharClass *Char_div(CharClass *this, CharClass *other)
{
    Object  *p1 = new(Char, this->c);

    if (other->c == 0)
        raise("Error: Can't divide by zero");
    ((CharClass *)p1)->c = this->c / other->c;
    return (p1);
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    if (this->c == other->c)
        return (true);
    return (false);
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    if (this->c > other->c)
        return (true);
    return (false);
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    if (this->c < other->c)
        return (true);
    return (false);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_to_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

const Class   *Char = (const Class *)&_description;
