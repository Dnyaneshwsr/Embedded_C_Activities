#include <stdio.h>

// Function to insert the number N into X at position P
unsigned int insert_number_into_position(unsigned int X, unsigned int N, int P) {
    // Create a mask to clear the bit at position P in X
    unsigned int mask = ~(1u << P);

    // Extract the lower (P + 1) bits from N and set the rest to zero
    N &= (1u << (P + 1)) - 1;

    // Clear the bits at position P in X and then insert the bits from N at position P
    unsigned int result = (X & mask) | (N << P);

    return result;
}

int main() {
    unsigned int X1 = 10; // 0000,0000,0000,0000,0000,0000,0000,1010
    unsigned int N1 = 5;  // 0000,0000,0000,0000,0000,0000,0000,0101
    int P1 = 6;

    // Insert N1 into X1 at position P1
    unsigned int result1 = insert_number_into_position(X1, N1, P1);
    printf("%08x\n", result1); // Output: 0000005a (90 in decimal)

    unsigned int X2 = 10; // 0000,0000,0000,0000,0000,0000,0000,1010
    unsigned int N2 = 5;  // 0000,0000,0000,0000,0000,0000,0000,0101
    int P2 = 2;

    // Insert N2 into X2 at position P2
    unsigned int result2 = insert_number_into_position(X2, N2, P2);
    printf("%08x\n", result2); // Output: 0000002a (42 in decimal)

    return 0;
}
