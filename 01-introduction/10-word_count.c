// Count lines, words, and characters in input.
//-----------------------------------------------------------------------------

#include <stdio.h>

#define IN  1  // Inside a word.
#define OUT 0  // Outside a word. 

int main(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    // This is equivalent to writing:
    // nl = (nw = (nc = 0));
    // Assignment is an expression with a value, associating left to right.
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        // It is guaranteed that evaluation will stop as soon as the truth
        // value is known.
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
