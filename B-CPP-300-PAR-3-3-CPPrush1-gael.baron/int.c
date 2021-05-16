/*
** EPITECH PROJECT, 2021
** int
** File description:
** functions
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

#ifndef INT_TO_CHAR
#define INT_TO_CHAR 11
#endif

typedef struct
{
    Class   base;
    char *str;
    int     nb;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->nb = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    if (this && this->str)
        free(this->str);
}

// Create additional functions here

static char *Int_to_str(IntClass *this)
{
    int size = INT_TO_CHAR + strlen(this->base.__name__) + 5 + 1;

    this->str = malloc(sizeof(char) * size);
    snprintf(this->str, size, "<%s (%d)>", this->base.__name__,
             this->nb);
    return (this->str);
}

static IntClass *Int_add(IntClass *this, IntClass *other)
{
    Object  *p1 = new(Int, this->nb);

    ((IntClass *)p1)->nb = this->nb + other->nb;
    return (p1);
}

static IntClass *Int_sub(IntClass *this, IntClass *other)
{
    Object  *p1 = new(Int, this->nb);

    ((IntClass *)p1)->nb = this->nb - other->nb;
    return (p1);
}

static IntClass *Int_mul(IntClass *this, IntClass *other)
{
    Object  *p1 = new(Int, this->nb);

    ((IntClass *)p1)->nb = this->nb * other->nb;
    return (p1);
}

static IntClass *Int_div(IntClass *this, IntClass *other)
{
    Object  *p1 = new(Int, this->nb);

    if (other->nb == 0)
        raise("Error: Can't divide by zero");
    ((IntClass *)p1)->nb = this->nb / other->nb;
    return (p1);
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    if (this->nb == other->nb)
        return (true);
    return (false);
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    if (this->nb > other->nb)
        return (true);
    return (false);
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    if (this->nb < other->nb)
        return (true);
    return (false);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_to_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .nb = 0
};

const Class   *Int = (const Class *)&_description;
