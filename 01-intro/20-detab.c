//
// detab
//
// Replaces tabs in the input with the proper number of blanks to space to the
// next tab stop. Assume a fixed set of tab stops, say every n columns.
//------------------------------------------------------------------------------

/*
    Example test run:
        a	b
        a.......b
        aaa     b
        aaa.....b
        aaa	bb 
        aaa.....bb
        aaa	bb	c
        aaa.....bb......c
        aaa	bb	cc 
        aaa.....bb......cc
        aaaaaaaabbbbb	cc
        aaaaaaaabbbbb...cc
        aaaaaaaa     	cc
        aaaaaaaa........cc
*/

#include <stdio.h>

#define MAXLINE  1000  // Maximum input line size.
#define COLWIDTH 8     // Fixed width for columns.

int getline_(char line[], int maxline);

main()
{
    char iline[MAXLINE];  // Current input line.
    char oline[MAXLINE];  // Detabbed output line.
    int ii;  // Indexes input.
    int oi;  // Indexes output.
    int len, ts, gap;

    while ((len = getline_(iline, MAXLINE)) != -1) {
        // If line has tab:
        if (len > 0) {
            ts = COLWIDTH;
            oi = 0;
            for (ii = 0; ii < len; ii++) {
                char c = iline[ii];

                // Update oline with the appropriate number of spaces.
                if (c == '\t') {
                    gap = ts - oi;
                    for (int j = 0; j < gap; ++j) {
                        oline[oi+j] = '.';
                    }
                    // Update the oline indexer so we can continue filling in
                    // chars after the tab.
                    oi = oi+gap;
                
                // Copy c to oline. Use oi because iline and oline may have
                // have different lengths and indices.
                } else {
                    oline[oi] = c;
                    ++oi;
                }
                // Update location of next tab stop.
                if (oi == ts)
                    ts = ts + COLWIDTH;
            }
            printf("%s", oline);
        }
    }
    return 0;
}

// getline_: Read a line into s, return line length if line has tab, 0 if no 
// tab in line, -1 if EOF.
int getline_(char s[], int lim)
{
    int c, i, hastab;

    hastab = 0;
    for (i = 0; i < lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i) {
        s[i] = c;
        if (c == '\t')
            hastab = 1;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    // Tri-state return: 0 if no tab, -1 if EOF, line-length if has tab.
    if (i == 0)
        return -1;
    if (!hastab)
        return 0;
    return i;
}


