//
// bits
//
// Playing around with bits
//-----------------------------------------------------------------------------

#include <stdio.h>

main()
{
    int a, b, c;

    a = 1, b = 2;

    // a's bit pattern is 00000001
    // b's bit pattern is 00000010
    // 
    // a & b compares the bits in each position in a to their respective
    // position's in b.
    //
    // a   b   c
    // 0 & 0 = 0
    // 0 & 0 = 0
    // 0 & 0 = 0
    // 0 & 0 = 0
    // 0 & 0 = 0
    // 0 & 0 = 0
    // 0 & 1 = 0
    // 1 & 0 = 0
    c = a & b;
    printf("%d\n", c);  // This will print 0.
}
