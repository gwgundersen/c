// Print longest input line.
//-----------------------------------------------------------------------------

#include <stdio.h>

#define MAXLINE 1000    // Maximum input line size.

int max;                // Maximum length seen so far.
char line[MAXLINE];     // Current input line.
char longest[MAXLINE];  // Longest line so far.

int getline_(void);
void copy(void);

int main(void)
{
    int len;  // Current line length.
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline_()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0)  // If there was a line.
        printf("%s", longest);
    return 0;
}

// getline_: Specialized version.
int getline_(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

// copy: Specialized version.
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
