#include <stdio.h>

// Macro to convert decimal to BCD
#define DEC_TO_BCD(decimal) (((decimal / 10) << 4) | (decimal % 10))

// Function to convert decimal to BCD
unsigned char dec_to_bcd(unsigned char decimal) {
    return ((decimal / 10) << 4) | (decimal % 10);
}

int main() {
    unsigned char decimal = 45; // Example decimal number
    unsigned char bcd_macro = DEC_TO_BCD(decimal);
    unsigned char bcd_function = dec_to_bcd(decimal);

    printf("Decimal: %d\nBCD (Macro): 0x%02X\nBCD (Function): 0x%02X\n", decimal, bcd_macro, bcd_function);

    return 0;
}
