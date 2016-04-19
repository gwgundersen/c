//
// modloop
//
// Write a loop equivalent to the for loop below without using && or ||:
//
// for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//     s[i] = c;
//-----------------------------------------------------------------------------

#include <stdio.h>

int loop(char s[], int lim);

main()
{
    int i, lim;
    lim = 1000;
    char s[lim];

    // Using function because `break` has not been introduced by K&R yet.
    int len = loop(s, lim);

    for (i=0; i<len; ++i)
        putchar(s[i]);
    putchar('\n');
}

// loop: Simulates for loop specified at top of file.
int loop(char s[], int lim)
{
    int i, done;
    char c;

    i = 0;
    done = 0;
    while ((c = getchar()) != EOF) {
        if (i >= lim-1)
            return i;
        else if (c == '\n')
            return i;
        else {
            s[i] = c;
            ++i;
        }
    }
    return i;
}
