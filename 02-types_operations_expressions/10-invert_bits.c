// Invert subset of bits in bit pattern.
//-----------------------------------------------------------------------------

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
unsigned mask_query(int p, int n);

int main(void)
{
    int x, p, n;

    x = 19919;
    p = 10;
    n = 7;
    printf("%d\n", invert(x, p, n));
}

// invert: Return x with the n bits that begin at position p inverted (i.e. 1
// changed into 0 and vice versa), leaving the other unchanged.
unsigned invert(unsigned x, int p, int n)
{
    unsigned a, b;

    // Let z pairwise denote ~x.
    // 0000 0000 0zzz zzzz 0000
    a = ~x & mask_query(p, n);

    // xxxx xxxx x000 0000 xxxx
    b = x & ~mask_query(p, n); 

    // xxxx xxxx xzzz zzzz xxxx
    return a | b;
}

// mask_query: Return mask to query n bits at position p.
//
// Example
// -------
//
// Values:
//   p = 10
//   n = 7
//
// Create mask and shift:
//   0                        0000 0000 0000 0000
//   ~0                       1111 1111 1111 1111
//   ~0 << n                  1111 1111 1000 0000
//   ~(~0 << n)               0000 0000 0111 1111
//   ~(~0 << n) << (p+1-n)    0000 0111 1111 0000
//
unsigned mask_query(int p, int n)
{

    return ~(~0U << n) << (p+1-n);
}
