// Copy input to output, replacing each string of one or more blanks by a
// single blank.
//-----------------------------------------------------------------------------

#include <stdio.h>

int main(void)
{
    int c, fl;

    fl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            fl = 1;
        } else {
            if (fl == 1) {
                fl = 0;
                putchar(' ');
            }
            putchar(c);
        }
    }
}
