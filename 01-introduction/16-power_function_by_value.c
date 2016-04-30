// Define a function power(m,n) to raise an integer m to a power n.
//-----------------------------------------------------------------------------

// In C functions, all argumented as pased by value. Here, we show a slightly
// more compact program (notice the power function has one less variable than
// the previous version.

#include <stdio.h>

int power(int m, int n);

int main(void)
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d\t%d\t%d\n", i, power(2,i), power(-3,i));
    return 0;
}

// power: Raise a base to n-th power; n >= 0.
int power(int base, int n)
{
    int p;

    p = 1;
    for (int p = 1; n > 0; --n)
        p = p * base;
    return p;
}
