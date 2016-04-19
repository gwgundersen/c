//
// ranges
//
// Determine ranges of char, short, int, and long variables, both signed and
// unsigned, by printing appropriate values from standard headers and by direct
// computation.
//-----------------------------------------------------------------------------

#include <limits.h>
#include <stdio.h>

main()
{
    printf("RANGES*\n\n");

    printf("Signed char:\t%d\t\t\t%d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char:\t%d\t\t\t%d\n", 0, UCHAR_MAX);
    printf("Signed short:\t%d\t\t\t%d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short:\t%d\t\t\t%d\n", 0, USHRT_MAX);
    printf("Signed int:\t%d\t\t%d\n", INT_MIN, INT_MAX);
    printf("Unsigned int:\t%d\t\t\t%d\n", 0, UINT_MAX);
    printf("Signed long:\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long:\t%d\t\t\t%lu\n", 0, ULONG_MAX);

    printf("\n* When signed, 0 is considered positive:\n");
    printf("  See: https://en.wikipedia.org/wiki/Signed_zero\n");
}

