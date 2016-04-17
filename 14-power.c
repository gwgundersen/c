//
// power
//
// Define a function power(m,n) to raise an integer m to a power n.
//------------------------------------------------------------------------------

// A function provides a convenient way to encapsulate some computation, which
// can then be used without worrying about its implementation.
//
// Generally, K&R use "parameter" for a variable named in the parenthesized
// list in a function definition, and "argument" for the value used in a call
// of the function.
//
// "Formal argument" and "actual argument" can be used to make the same
// distinction.

#include <stdio.h>

// Called a "function prototype." It must agree with its definition and usage.
// Parameter names are optional and need not agree with the definition.
int power(int m, int n);

main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d\t%d\t%d\n", i, power(2,i), power(-3,i));

    // First time we've seen main return anything. The caller of main is the
    // the environment in which the program is executed. Typically, 0 implies
    // normal termination.
    return 0;
}

// power: raise a base to n-th power; n >= 0
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (int i = 0; i <= n; ++i)
        p = p * base;
    return p;
}
