/*
** EPITECH PROJECT, 2021
** vertex
** File description:
** functions
*/

#include "vertex.h"
#include "new.h"

#ifndef INT_TO_CHAR
#define INT_TO_CHAR 11
#endif

typedef struct
{
    Class   base;
    int     x, y, z;
    char *str;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this && this->str)
        free(this->str);
}

// Create additional functions here
static char *Vertex_to_str(VertexClass *this)
{
    int size = INT_TO_CHAR * 3 + strlen(this->base.__name__) + 9 + 1;

    this->str = malloc(sizeof(char) * size);
    snprintf(this->str, size, "<%s (%d, %d, %d)>", this->base.__name__,
             this->x, this->y, this->z);
    return (this->str);
}

static VertexClass *Vertex_add(VertexClass *this, VertexClass *other)
{
    Object  *p1 = new(Vertex, this->x, this->y);

    ((VertexClass *)p1)->x = this->x + other->x;
    ((VertexClass *)p1)->y = this->y + other->y;
    ((VertexClass *)p1)->z = this->z + other->z;
    return (p1);
}

static VertexClass *Vertex_sub(VertexClass *this, VertexClass *other)
{
    Object  *p1 = new(Vertex, this->x, this->y);

    ((VertexClass *)p1)->x = this->x - other->x;
    ((VertexClass *)p1)->y = this->y - other->y;
    ((VertexClass *)p1)->z = this->z - other->z;
    return (p1);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_to_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
