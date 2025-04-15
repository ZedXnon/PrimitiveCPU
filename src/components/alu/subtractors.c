#include "subtractors.h"

bool borrow_out;
bool difference;

void half_subtractor(bool a,bool  b, bool *difference, bool *borrow_out)
{
    *difference = xor(a, b);
    *borrow_out = and(not(a), b);
}

// void full_subtractor(bool borrow_in, bool a, bool  b, bool *difference, bool *borrow_out)
// {
//     bool not_a;
//     not_a = not(a);
//     xor(xor(a, b), borrow_in)
//     and(not_a, b)
// }