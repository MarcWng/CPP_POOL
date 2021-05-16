/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

#ifndef INT_TO_CHAR
#define INT_TO_CHAR 11
#endif

typedef struct
{
    Class   base;
    char *str;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this && this->str)
        free(this->str);
}

// Create additional functions here
static char *Point_to_str(PointClass *this)
{
    int size = INT_TO_CHAR * 2 + strlen(this->base.__name__) + 7 + 1;

    this->str = malloc(sizeof(char) * size);
    snprintf(this->str, size, "<%s (%d, %d)>", this->base.__name__,
             this->x, this->y);
    return (this->str);
}

static PointClass *Point_add(PointClass *this, PointClass *other)
{
    Object  *p1 = new(Point, this->x, this->y);

    ((PointClass *)p1)->x = this->x + other->x;
    ((PointClass *)p1)->y = this->y + other->y;
    return (p1);
}

static PointClass *Point_sub(PointClass *this, PointClass *other)
{
    Object  *p1 = new(Point, this->x, this->y);

    ((PointClass *)p1)->x = this->x - other->x;
    ((PointClass *)p1)->y = this->y - other->y;
    return (p1);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_to_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
