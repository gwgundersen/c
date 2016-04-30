// Returns value of integer x rotated to the right by n bit positions.
//-----------------------------------------------------------------------------

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
    unsigned x, z;
    int n;

    x = 2147483719;
    n = 2;
    z = rightrot(x, n);  // 286
    printf("%d\n", z);
}

// rightrot: Return value of the integer x rotated to the right by n bit 
// positions.
//
// Example
// -------
//
// Values:
//   n = 2
//   x = 2147483719    1000 0000 0000 0000 0000 0000 0100 0111
//
// Shift bits left:
//   x << n            0000 0000 0000 0000 0000 0001 0001 1100
//
// Right bits right:
//   x >> (32 - n)     0000 0000 0000 0000 0000 0000 0000 0010
// 
// OR the two expressions:
//   a                 0000 0000 0000 0000 0000 0001 0001 1100
//   b                 0000 0000 0000 0000 0000 0000 0000 0010
//   a | b             0000 0000 0000 0000 0000 0001 0001 1110
//
// Result:
//   286               0000 0000 0000 0000 0000 0001 0001 1110
//
unsigned rightrot(unsigned x, int n)
{
    if (n == 0)
        return x;
    return (x << n) | (x >> (32 - n));
}
