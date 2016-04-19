//
// tempwhile
//
// Print Fahrenheit-Celsius table.
//-----------------------------------------------------------------------------

#include <stdio.h>

main()
{
    // Variable declarations: type information and symbols.
    // The range of both int and float types are machine-dependent.
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {

        // First multiply by 5 and then divide by 9 because integer division
        // truncates. Since 5 and 9 are both integers, (5/9) would be truncated
        // to 0.
        celsius = 5 * (fahr-32) / 9;

        // %d specifies an integer argument.
        // The optional integer between % and d specifies the width.
        //
        // printf is *not* part of the C language; there is no IO defiened by C
        // itself. printf is just a useful function that is typically available
        // to C programs through the standard library.
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

