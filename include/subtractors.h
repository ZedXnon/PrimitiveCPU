#ifndef ADDERS_H
#define ADDERS_H

#include "logic_gates.h"
#define BITS 16

void ripple_carry_subtractor(bool a[16], bool b[16], bool difference[16], bool *borrow_out);
void full_subtractor(bool borrow_in, bool a, bool b, bool *difference, bool *borrow_out);
void half_subtractor(bool a, bool b, bool *difference, bool *borrow_out);

#endif