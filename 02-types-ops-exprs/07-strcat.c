// Concatenates two strings together.
//-----------------------------------------------------------------------------

#include <stdio.h>

void strcat_(char s[], char t[]);

int main(void)
{
    // If you do not allocate enough memory, you will get a runtime error,
    // "Abort trap: 6."
    char s[13]; 
    s[0] = 'h';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = ',';
    s[6] = ' ';
    s[7] = '\0';

    // Notice strcat_ does not return anything. By passing a char array, we
    // really pass a pointer. When we print s, we start printing at the
    // pointer.
    strcat_(s, "world");
    printf("%s\n", s);
}

// strcat_: Concatenate t to end of s; assume is big enough.
void strcat_(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')  // Find end of s
        i++;

    // This illustrates the increment and decrement operators. The expression
    // ++n increments n before it is used; n++ increments n after it is used.
    // 
    // Here, we copy each element over, increment each index, and compare the
    // next value--the one that has not been copied yet--to '\0'.
    while ((s[i++] = t[j++]) != '\0')  // Copy t
        ;
}
