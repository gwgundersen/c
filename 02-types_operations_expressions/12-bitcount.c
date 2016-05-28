// Counts 1-bits in integer argument.
//-----------------------------------------------------------------------------

#include <stdio.h>

#define WORDSIZE 32

unsigned bitcount(unsigned x);
unsigned _bitcount(unsigned x);

int main(void)
{
    printf("%d\n", bitcount(20));  // 10100 -> 2
    printf("%d\n", _bitcount(20));  // 10100 -> 2
    //_bitcount(20);
}

// bitcount: count 1 bits in x.
unsigned bitcount(unsigned x)
{
    int b;

    // Iterate over digits in x, right-shifting the digits until the number is
    // all 0s.
    for (b = 0; x != 0; x >>= 1)
        // This checks if the right-most digit is 1. I'm not sure why the
        // preceding 0 is necessary.
        if (x & 01)
            b++;
    return b;
}

// _bitcount: In a two's complement number system, `x &= (x-1)` deletes the
// rightmost 1-bit in x. Use this observation to write a faster version of
// bitcount.
//
// Explanation:
//
// 5
// -7
// 
//
// x          0000 1010 0010 0000
// 1          0000 0000 0000 0001
// x-1        0000 1010 0001 1111  This step was tricky for me. But think about
//                                 it with smaller numbers, e.g.:
//                                 1000 - 0001 = 0111
// x & (x-1)  0000 1010 0000 0000
//
// We've successfully removed the right-most 1.
unsigned _bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}
