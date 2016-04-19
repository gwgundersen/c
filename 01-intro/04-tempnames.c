//
// tempnames
//
// Print Fahrenheit-Celsius table.
//-----------------------------------------------------------------------------

#include <stdio.h>

// These quantities are symbol constants, not variables. They conventionally 
// are written in upper case.
// 
// Notice that types are not declared. The preprocessor just replaces their
// symbols with their respective values before compiling.
//
#define LOWER 0    // Lower limit of table.
#define UPPER 300  // Upper limit.
#define STEP  29   // Step size.

main()
{
    // Compared to exercise 3, most variables are eliminated. They appear as
    // constants in the for-loop construction.
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}


