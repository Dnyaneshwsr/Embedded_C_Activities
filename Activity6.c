#include <stdio.h>

// Define the INTCON register as a union of an unsigned char and a bitfield structure
typedef union {
    struct {
        unsigned int RBIF    : 1;
        unsigned int INT0IF  : 1;
        unsigned int TMR0IF  : 1;
        unsigned int RBIE    : 1;
        unsigned int INT0IE  : 1;
        unsigned int TMR0IE  : 1;
        unsigned int PEIE    : 1;
        unsigned int GIE     : 1;
    } bits;
    unsigned char all;
} INTCON_Register;

int main() {
    // Create an instance of the INTCON_Register union
    INTCON_Register intcon;

    // Access the INTCON register bitwise
    intcon.bits.RBIF   = 0;
    intcon.bits.INT0IF = 1;
    intcon.bits.TMR0IE = 1;
    intcon.bits.GIE    = 1;

    // Access the INTCON register bytewise
    intcon.all = 0x82;

    // Example statements
    printf("INTCON: 0x%02X\n", intcon.all); // Output: INTCON: 0x82
    printf("GIE: %d\n", intcon.bits.GIE);   // Output: GIE: 1
    printf("INT0IF: %d\n", intcon.bits.INT0IF); // Output: INT0IF: 1

    return 0;
}
