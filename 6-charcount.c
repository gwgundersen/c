//
// charcount
//
// Count characters from input.
//------------------------------------------------------------------------------

#include <stdio.h>

main()
{
    // long integers are at least 32 bits.
    long nc;

    // It seems idiomatic, at least to K&R, to declare and initialize their
    // variables in two separate steps, no matter how easy it might be to
    // combine them.
    nc = 0;
    while (getchar() != EOF) {
        // Increment by 1.
        ++nc;
    }

    // Press control-D in order to send an EOF without actually ending the
    // program, i.e. pressing control-C. See:
    // http://stackoverflow.com/a/21365313/1830334
    printf("------\n");
    printf("%ld\n", nc);
}
