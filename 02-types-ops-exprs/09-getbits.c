//
// getbits
//
// Get bits from integral type.
//-----------------------------------------------------------------------------

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

main()
{
    int x, p, n;

    x = 63;
    p = 4;
    n = 3;
    printf("%d\n", getbits(x, p, n));
}

// getbits: Get n bits from position p.
unsigned getbits(unsigned x, int p, int n)
{
    // Right expression:
    //   This is just a method of taking the first n bits of any number to
    //   which you apply &. We cannot directly generate an arbitrarily long bit 
    //   pattern of 1s, since we do not know the size of the unsigned integer.
    //
    //   0                              0000 0000 0000 0000
    //   ~0                             1111 1111 1111 1111
    //   ~0 << n                        1111 1111 1111 1000
    //   ~(~0 << n)                     0000 0000 0000 0111
    //
    // Left expression:
    //   This right-shifts the bit pattern of the number we want to examine so
    //   that it is right-justified at the appropriate location. Alternatively,
    //   we could have left-shifted the above mask.
    //
    //   x = 63                         0000 0000 0011 1111
    //   x >> p+1-n                     0000 0000 0000 1111
    //
    // Combined expression:
    //
    //   (x >> (p+1-n)) & ~(~0 << n)    0000 0000 0000 0111
    //   111 to decimal                 7

    return (x >> (p+1-n)) & ~(~0 << n);
}
