/*
** EPITECH PROJECT, 2021
** new
** File description:
** functions
*/

#include "new.h"
#include "player.h"
#include "object.h"
#include <stdarg.h>

Object  *new(const Class *class, ...)
{
    Object *obj = NULL;
    va_list list;

    if (class) {
        obj = malloc(class->__size__);
        if (!obj) {
            raise("Out of memory");
            return (NULL);
        }
        memcpy(obj, class, class->__size__);
        if (class->__ctor__) {
            va_start(list, class);
            ((const Class *)obj)->__ctor__(obj, &list);
            va_end(list);
        }
        return (obj);
    }
    raise("Class is empty");
    return (NULL);
}

Object  *va_new(const Class *class, va_list* ap)
{
    Object *obj = NULL;

    if (class) {
        obj = malloc(class->__size__);
        if (!obj) {
            raise("Out of memory");
            return (NULL);
        }
        memcpy(obj, class, class->__size__);
        if (class->__ctor__)
            ((const Class *)obj)->__ctor__(obj, ap);
        return (obj);
    }
    raise("Class is empty");
    return (NULL);
}

void delete(Object *ptr)
{
    if (ptr && ((Class *)ptr)->__dtor__)
        (((Class *)ptr)->__dtor__)(ptr);
    free(ptr);
}
