#include "subtractors.h"

bool borrow_out;
bool difference;

void half_subtractor(bool a, bool b, bool *difference, bool *borrow_out)
{
    *difference = xor(a, b);
    *borrow_out = and(not(a), b);
}

void full_subtractor(bool borrow_in, bool a, bool b, bool *difference, bool *borrow_out)
{
    bool xor_inputs;

    xor_inputs = xor(a, b);
    *difference = xor(borrow_in, xor_inputs);
    *borrow_out = or(and(not(a), b), and(borrow_in, not(xor_inputs)));
}

void ripple_carry_subtractor(bool a[16], bool b[16], bool difference[16], bool *borrow_out)
{
    bool borrow_in;
    int i;

    half_subtractor(a[0], b[0], &difference[0], &borrow_in);
    for (i = 1; i < 16; i++)
        full_subtractor(borrow_in, a[i], b[i], &difference[i], &borrow_in);
    *borrow_out = borrow_in;
}