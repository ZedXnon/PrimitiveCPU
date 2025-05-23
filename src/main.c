#include <stdio.h>
#include <stdbool.h>
#include "subtractors.h"

// Helper function to print a 16-bit binary number
void print_bits(bool bits[16]) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1: Simple Subtraction (No borrow out)
    // 5 - 2 = 3
    bool a[16] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 5 in binary (LSB first)
    bool b[16] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 2 in binary (LSB first)
    bool difference[16];
    bool borrow_out;

    printf("Test 1: 5 - 2 = 3 (No borrow out expected)\n");
    ripple_carry_subtractor(a, b, difference, &borrow_out);
    printf("A:         ");
    print_bits(a);
    printf("B:         ");
    print_bits(b);
    printf("DIFFERENCE: ");
    print_bits(difference);
    printf("BORROW OUT: %d\n\n", borrow_out);

    // Test case 2: Subtraction with Borrow
    // 3 - 7 = -4 (represented in two's complement, with borrow)
    bool c[16] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 3 in binary (LSB first)
    bool d[16] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 7 in binary (LSB first)
    
    printf("Test 2: 3 - 7 = -4 (Borrow out expected)\n");
    ripple_carry_subtractor(c, d, difference, &borrow_out);
    printf("A:         ");
    print_bits(c);
    printf("B:         ");
    print_bits(d);
    printf("DIFFERENCE: ");
    print_bits(difference);
    printf("BORROW OUT: %d (Should be 1 indicating negative result)\n\n", borrow_out);

    // Test case 3: Edge case with borrowing across multiple positions
    // 16 - 15 = 1 (requires multiple borrows)
    bool e[16] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 16 in binary (LSB first)
    bool f[16] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 15 in binary (LSB first)
    
    printf("Test 3: 16 - 15 = 1 (Multiple borrows, but no borrow out)\n");
    ripple_carry_subtractor(e, f, difference, &borrow_out);
    printf("A:         ");
    print_bits(e);
    printf("B:         ");
    print_bits(f);
    printf("DIFFERENCE: ");
    print_bits(difference);
    printf("BORROW OUT: %d\n\n", borrow_out);

    return 0;
}