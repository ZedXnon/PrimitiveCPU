#include <stdio.h>
#include <stdbool.h>
#include "adders.h"  // Assuming your ripple_carry_adder and helpers are here

// Helper function to print a 16-bit binary number
void print_bits(bool bits[16]) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1: Simple Addition (No overflow)
    bool a[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};  // 2 in binary
    bool b[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};  // 1 in binary
    bool sum[16];
    bool carry_out;

    printf("Simple Addition:\n");
    ripple_carry_adder(a, b, sum, &carry_out);
    printf("A:    ");
    print_bits(a);
    printf("B:    ");
    print_bits(b);
    printf("SUM:  ");
    print_bits(sum);
    printf("CARRY OUT: %d\n\n", carry_out);

    // Test case 2: Overflow Addition (carry out = 1)
    bool c[16] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};  // 32768 in binary
    bool d[16] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};  // 1 in binary

    printf("Overflow Addition:\n");
    ripple_carry_adder(c, d, sum, &carry_out);
    printf("A:    ");
    print_bits(c);
    printf("B:    ");
    print_bits(d);
    printf("SUM:  ");
    print_bits(sum);
    printf("CARRY OUT: %d\n\n", carry_out);

    return 0;
}
