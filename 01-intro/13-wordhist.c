//
// wordhist
//
// Print a histogram of the lengths of words in input.
//------------------------------------------------------------------------------

#include <stdio.h>

#define MAX_LEN 20  // Maximum length we can count for each word.
#define IN      1   // Inside a word.
#define OUT     0   // Outside a word.

main()
{
    int c, state, len, i, j;
    int lword[MAX_LEN];

    state = OUT;
    len = 0;
    for (i = 0; i < MAX_LEN; ++i)
        lword[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (len > 0)
                ++lword[len];
            state = OUT;
            len = 0;
        } else if (state == OUT) {
            state = IN;
            ++len;
        } else
            ++len;
    }

    // Do not display the 0-length bin, which is always empty.
    for (i = 1; i < MAX_LEN; ++i) {
        printf("%d ", i);
        if (lword[i] == 0)
            printf("\t.");
        else
            printf("\t=");
        // Begin at 1 because we already printed the first count.
        for (j = 1; j < lword[i]; ++j)
            putchar('=');
        putchar('\n');
    }
}
