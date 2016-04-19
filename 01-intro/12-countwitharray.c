//
// countwitharray
//
// Count digits, white space, and others.
//-----------------------------------------------------------------------------

#include <stdio.h>

main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        // c is a char, not an int. We can check if it is a digit by comparing
        // its character set value with '0' and '9'. This works because all
        // character sets represent 0-9 in increasing values.
        if (c >= '0' && c <= '9')
            // c-'0' converts the character set integer value to 0-9.
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
