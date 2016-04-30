//
// setbits
//
// Set bits shifts a bit pattern within an integral type.
//-----------------------------------------------------------------------------

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
    unsigned x, y, z;
    int p, n;

    x = 315;
    p = 5;
    n = 3;
    y = 9;
    z = setbits(x, p, n, y);
    printf("%d\n", z);
}

// setbits: Return x with the n bits that begin at position p set to the
// rightmost n bits of y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // Example using values:
    // x = 315
    // p = 5
    // n = 3
    // y = 9

    // Shift y bits to where they will be inserted in x:
    //
    // 0                                 0000 0000 0000 0000
    // ~0                                1111 1111 1111 1111
    // ~0 << n                           1111 1111 1111 1000
    // ~(~0 << n)                        0000 0000 0000 0111
    // ~(~0 << n) & y                    0000 0000 0000 0001  n number of y bits
    //                                                   ---
    // (~(~0 << n) & y) << (p+1-n)       0000 0000 0000 1000  y bits shifted p positions to x
    //                                               -- -
    unsigned a = (~(~0 << n) & y) << (p+1-n);  //             8 in decimal

    // Create 0-mask where y bits will go on x:
    //
    // 0                                 0000 0000 0000 0000
    // ~0                                1111 1111 1111 1111
    // ~0 << n                           1111 1111 1111 1000
    // ~(~0 << n)                        0000 0000 0000 0111
    // ~(~0 << n) << (p+1-n)             0000 0000 0011 1000
    // ~(~(~0 << n) << (p+1-n))          1111 1111 1100 0111
    //                                               -- -
    // (~(~(~0 << n) << (p+1-n))) & x    0000 0001 0000 0011
    //                                               -- -
    unsigned b = (~(~(~0 << n) << (p+1-n))) & x;  //          259 in decimal

    // a                                 0000 0000 0000 1000
    // b                                 0000 0001 0000 0011
    // a | a                             0000 0001 0000 1011  267 in decimal
    return a | b;
}
