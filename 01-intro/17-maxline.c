//
// maxline
//
// Print longest input line.
//-----------------------------------------------------------------------------

// This code is designed to highlight an important fact about arrays: while C
// functions pass arguments by value, the value passed when the name of an
// array is used is location or address of the beginning of the array. The
// array elements are not copied.
//
// Notice that both `copy` and `getline` mutate their argument arrays.

#include <stdio.h>

#define MAXLINE 1000  // Maximum input line size.

// `getline` is a function defined in <stdio.h> in current versions. Probably
// was not defined for K&R. The compiler will throw an exception if you name
// the function `getline`.
int getline_(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;  // Current line length.
    int max;  // Maximum length seen so far.
    
    // Notice we have to set aside storage for the array. In most modern
    // languages, this is not necessary. In C, we must specify how big the
    // data can be in advance.
    char line[MAXLINE];     // Current input line.
    char longest[MAXLINE];  // Longest line so far.

    max = 0;
    while ((len = getline_(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)  // If there was a line.
        printf("%s", longest);
    return 0;
}

// getline_: Read a line into s, return length.
int getline_(char s[], int lim)
{
    int c, i;

    // While c is not EOF or newline, read it into s.
    for (i = 0; i < lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
        s[i] = c;
    // If c is the newline character, read it in and increment the count. The
    // alternative is that c is EOF.
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    // If the line is EOF, then i==0. Otherwise, at a minimum, i==1.
    return i;
}

// copy: Copy `from` into `to`; assume `to` is big enough.
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
