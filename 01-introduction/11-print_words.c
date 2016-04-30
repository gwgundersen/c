// Print input one word per line.
//-----------------------------------------------------------------------------

#include <stdio.h>

#define IN  1  // Inside a word.
#define OUT 0  // Outside a word. 

int main(void)
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state != OUT) {
                state = OUT;
                putchar('\n');
            }
        } else if (state == OUT) {
            state = IN;
            putchar(c);
        } else if (state == IN) {
            putchar(c);
        }
    }
}

