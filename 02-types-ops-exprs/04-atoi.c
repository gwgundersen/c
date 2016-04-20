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
        // (s[i] - '0') works for all character sets because they all represent
        // '0', '1', '2', ... in contiguous order AND because they all begin
        // with the numbers 0, 1, 2, ...
        // 
        // For example, let's say the character set numerical value for '0' was
        // X. Then '3' would be X+3. And ('3' - '0') would be X + 3 - X = 3.
        n = 10 * n + (s[i] - '0');
    }
    return n;
}
