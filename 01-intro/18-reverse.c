//
// reverse
//
// Reverses its input a line at a time.
//-----------------------------------------------------------------------------

#include <stdio.h>

#define MAXLINE 1000  // Maximum input line size.

int getline_(char line[], int maxline);
void reverse(char to[], char from[], int lenline, int maxline);

main()
{
    int len;             // Current line length.
    char line[MAXLINE];  // Current input line.
    char rev[MAXLINE];   // Reversed input line.

    while ((len = getline_(line, MAXLINE)) > 0) {
        reverse(rev, line, len, MAXLINE);
        //printf("%s", rev);
    }
    return 0;
}

// getline_: Read a line into s, return length.
int getline_(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// reverse: Reverse chars from `from` into `to`; assume `to` is big enough.
void reverse(char to[], char from[], int len, int lim)
{
    int i;

    for (i = 0; i < lim-1 && from[i] != '\0'; ++i) {
        // The last char is '\0'. We do not want to copy this to the beginning
        // of the reversed word. Rather, we want to add it to the end.
        to[len-2-i] = from[i];
        to[len-1] = '\0';  // Equivalent to assigning from[len-1].
    }
    printf("%s\n", to);
}
