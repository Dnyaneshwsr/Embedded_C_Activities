#include <stdio.h>

// Macro to set a bit at the given position in an 8-bit number
#define SET_BIT(number, pos) ((number) |= (1u << (pos)))

// Macro to clear a bit at the given position in an 8-bit number
#define CLEAR_BIT(number, pos) ((number) &= ~(1u << (pos)))

// Macro to toggle a bit at the given position in an 8-bit number
#define TOGGLE_BIT(number, pos) ((number) ^= (1u << (pos)))

// Function to set a bit at the given position in an 8-bit number
unsigned char set_bit(unsigned char number, int pos) {
    return number | (1u << pos);
}

// Function to clear a bit at the given position in an 8-bit number
unsigned char clear_bit(unsigned char number, int pos) {
    return number & ~(1u << pos);
}

// Function to toggle a bit at the given position in an 8-bit number
unsigned char toggle_bit(unsigned char number, int pos) {
    return number ^ (1u << pos);
}

int main() {
    unsigned char number = 0b01011001; // Example 8-bit number (91 in decimal)

    // Using macros to set, clear, and toggle bits
    SET_BIT(number, 2);
    printf("Number after setting bit 2: 0x%02X\n", number);

    CLEAR_BIT(number, 4);
    printf("Number after clearing bit 4: 0x%02X\n", number);

    TOGGLE_BIT(number, 1);
    printf("Number after toggling bit 1: 0x%02X\n", number);

    // Using functions to set, clear, and toggle bits
    number = set_bit(number, 3);
    printf("Number after setting bit 3: 0x%02X\n", number);

    number = clear_bit(number, 2);
    printf("Number after clearing bit 2: 0x%02X\n", number);

    number = toggle_bit(number, 0);
    printf("Number after toggling bit 0: 0x%02X\n", number);

    return 0;
}
