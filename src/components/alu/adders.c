#include "adders.h"

bool carry_out;
bool sum;

void half_adder(bool a,bool  b, bool *sum, bool *carry_out)
{
    *sum = xor(a, b);
    *carry_out = and(a, b);
}

void full_adder(bool carry_in, bool a, bool b, bool *sum, bool *carry_out)
{
    bool xor_inputs;

    xor_inputs = xor(a, b);
    *sum = xor(carry_in, xor_inputs);
    *carry_out = or(and(a, b), and(carry_in, xor_inputs));
}

void ripple_carry_adder(bool a[16], bool b[16], bool sum[16], bool *carry_out)
{
    bool carry_in;
    int i;

    half_adder(a[0], b[0], &sum[0], &carry_in);
    for (i = 1; i < 16; i++)
        full_adder(carry_in, a[i], b[i], &sum[i], &carry_in);
    *carry_out = carry_in;
}