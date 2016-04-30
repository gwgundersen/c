// Count characters in input with for loop.
//-----------------------------------------------------------------------------

#include <stdio.h>

int main(void)
{
    double nc;
    // The body of the for loop is empty because all the work is done in the
    // test and increment sections. The grammatical rules of C require that a
    // for statement have a body. The isolated semicolon, called a "null
    // statment", satisfies the requirement.
    for (nc = 0; getchar() != EOF; ++nc)
        ;

    printf("------\n");
    printf("%.0f\n", nc);
}
