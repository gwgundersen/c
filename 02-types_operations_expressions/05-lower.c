// Converts character to lower case; ASCII only.
//-----------------------------------------------------------------------------

#include <stdio.h>

char lower(char c);

int main(void)
{
    char c = lower('X');
    printf("%c\n", c);
}

// lower: Converts c to lower case; ASCII only.
char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        // The ASCII table contains upper and lowercase letters in that order:
        //
        //   ABC...Z...abc...z
        //
        // When we subtract by 'A', we get the uppercase letter's numeric
        // value beginning with 'A'=0, 'B'=1, and so on. When we add 'a', we
        // increase (c-'A') by 97, shifting lowercase letters into uppercase.
        //
        // For example, if we begin with 'P' (80) and then subtract 'A' (65),
        // we get the 15th ASCII character because 'P' is the 16th (1 index)
        // letter in the alphabet. If we add 'a' (97), we get 'p' (112).
        //
        // For what it's worth, we could perform this operation with any
        // character that doesn't cause an overflow in the table, e.g.:
        //
        //   c + 'b' - 'B'
        //
        return c + 'a' - 'A';
    else
        return c;
}
