#include "mulisp.h"

Object *plus(Object *params, Environment *env)
{
    Object *ret = malloc(sizeof(Object));
    ret->type = OTYPE_INT;

    if (params->type == OTYPE_NIL)
        ret->integer.value = 0;
    else if (params->type == OTYPE_PAIR && params->pair.car->type == OTYPE_INT)
        ret->integer.value = params->pair.car->integer.value +
                             plus(params->pair.cdr, env)->integer.value;
    else
        fatal_error("Quite the illegal addition there");

    return ret;
}

Object *gt(Object *params, Environment *env)
{
    Object *ret = malloc(sizeof(Object));
    ret->type = OTYPE_BOOL;

    if (params->type == OTYPE_PAIR && params->pair.car->type == OTYPE_INT &&
        params->pair.cdr->type == OTYPE_PAIR &&
        params->pair.cdr->pair.car->type == OTYPE_INT &&
        params->pair.cdr->pair.cdr->type == OTYPE_NIL)
        ret->boolean.value = params->pair.car->integer.value >
                             params->pair.cdr->pair.car->integer.value;
    else
        fatal_error("Illegal comparison");

    return ret;
}