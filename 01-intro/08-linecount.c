//
// linecount
//
// Count lines in input.
//------------------------------------------------------------------------------

#include <stdio.h>

main()
{
    int c, nl;

    nl = 0;
    // The != operator has precedence over the = operator. Therefore, we must
    // use parentheses to enforce the correct order of operations. 
    //
    // This is idiomtic C.
    while ((c = getchar()) != EOF)
        // A character written in single quotes represents an integer value
        // equal to the numerical value of the character in the machine's
        // character set. For example, 'A' is a character constant; in the ASCII
        // character set, its value is 65.
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
