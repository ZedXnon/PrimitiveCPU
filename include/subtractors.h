#ifndef ADDERS_H
#define ADDERS_H

#include "logic_gates.h"
#define BITS 16

void ripple_carry_adder(bool a[BITS], bool b[BITS], bool sum[BITS], bool *carry_out);
void full_adder(bool carry_in, bool a, bool b, bool *sum, bool *carry_out);
void half_adder(bool a,bool  b, bool *sum, bool *carry_out);

#endif