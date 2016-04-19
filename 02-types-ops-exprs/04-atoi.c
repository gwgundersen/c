//
// atoi
//
// Convert string to integer.
//-----------------------------------------------------------------------------

#include <stdio.h>

int atoi(char s[]);

main()
{
    int i = atoi("3141592");
    printf("%d\n", i);
}

// atoi: Convert s to integer, e.g. "89" to 89.
int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        // 10 * n to move the virtual decimal place.
        //
        // (s[i] - '0') gives the numeric value of the character stored in s[i]
        // because the values '0', '1', ... form a contiguous increasing
        // sequence.
        //
        // In other words, (s[i] - '0') is casting types.
        n = 10 * n + (s[i] - '0');
    }
    return n;
}
