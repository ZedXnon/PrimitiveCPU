#include "logic_gates.h"

bool nand(bool a, bool b)
{
    return(not(and(a, b)));
}

bool nor(bool a, bool b)
{
    return(not(or(a, b)));
}

bool xor(bool a, bool b)
{
    return(or(and(a, not(b)), and(not(a), b)));
}

bool xnor(bool a, bool b)
{
    return(not(xor(a, b)));
}

bool and(bool a, bool b)
{
    return(a & b);
}

bool or(bool a, bool b)
{
    return(a | b);
}

bool not(bool a)
{
    return(!a);
}