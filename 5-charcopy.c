//
// charcopy
//
// Copy input to output using getchar() and putchar().
//------------------------------------------------------------------------------

// C's input/output model is simple: I/O, regardless of where it originates or
// where it goes, is dealth with as streams of characters. A "text stream" is a
// sequence of characters divided into lines; each line consists of zero or more
// characters followed by a newline character.

#include <stdio.h>

main()
{
    // The type char is specifically for storing character data but the type
    // int can be used as well. We use int because it is bigger than char and
    // can store the EOF value.
    int c;

    // Reads in a character from input.
    c = getchar();
    // EOF is an integer defined in <stdio.h>.
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
