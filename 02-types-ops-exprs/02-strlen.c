// Compute length of string.
//-----------------------------------------------------------------------------

#include <stdio.h>

int strlen_(char s[]);

int main(void)
{
    int len = strlen_("hello, world");
    printf("%d\n", len);
}

// strlen: Return length of s.
int strlen_(char s[])
{
    int i;

    i = 0;
    // Technically, a string constant is an array of characters. The internal
    // representation of a string has a null character '\0' at the end. The
    // physical storage required is one more than the number of characters
    // written between quotes.
    while (s[i] != '\0')
        ++i;
    return i;
}

