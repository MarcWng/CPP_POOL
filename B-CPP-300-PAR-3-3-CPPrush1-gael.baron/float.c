/*
** EPITECH PROJECT, 2021
** int
** File description:
** functions
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

#ifndef FLOAT_TO_CHAR
#define FLOAT_TO_CHAR 18
#endif

typedef struct
{
    Class   base;
    char *str;
    float     nb;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->nb = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (this && this->str)
        free(this->str);
}

// Create additional functions here

static char *Float_to_str(FloatClass *this)
{
    int size = FLOAT_TO_CHAR + strlen(this->base.__name__) + 5 + 1;

    this->str = malloc(sizeof(char) * size);
    snprintf(this->str, size, "<%s (%f)>", this->base.__name__,
             this->nb);
    return (this->str);
}

static FloatClass *Float_add(FloatClass *this, FloatClass *other)
{
    Object  *p1 = new(Float, this->nb);

    ((FloatClass *)p1)->nb = this->nb + other->nb;
    return (p1);
}

static FloatClass *Float_sub(FloatClass *this, FloatClass *other)
{
    Object  *p1 = new(Float, this->nb);

    ((FloatClass *)p1)->nb = this->nb - other->nb;
    return (p1);
}

static FloatClass *Float_mul(FloatClass *this, FloatClass *other)
{
    Object  *p1 = new(Float, this->nb);

    ((FloatClass *)p1)->nb = this->nb * other->nb;
    return (p1);
}

static FloatClass *Float_div(FloatClass *this, FloatClass *other)
{
    Object  *p1 = new(Float, this->nb);

    if (other->nb == 0.0)
        raise("Error: Can't divide by zero");
    ((FloatClass *)p1)->nb = this->nb / other->nb;
    return (p1);
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    if (this->nb == other->nb)
        return (true);
    return (false);
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    if (this->nb > other->nb)
        return (true);
    return (false);
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    if (this->nb < other->nb)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_to_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .nb = 0
};

const Class   *Float = (const Class *)&_description;
