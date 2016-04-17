//
// tempfunc
//
// Print Fahrenheit-Celsius table using a function.
//------------------------------------------------------------------------------

#include <stdio.h>

#define LOWER 0    // Lower limit of table.
#define UPPER 300  // Upper limit.
#define STEP  29   // Step size.

double fahr2celsius(int fahr);

main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d\t%6.1f\n", fahr, fahr2celsius(fahr));
}

// fahr2celsius: Converts Fahrenheit to Celsius.
double fahr2celsius(int fahr)
{
    return (5.0/9.0)*(fahr-32);
}
