//
// htoi
//
// Converts a string of hexadecimal digits (including an optional 0x or 0X)
// into its equivalent integer value. The allowable digits are 0 through 9, a
// through f, and A through F.
//-----------------------------------------------------------------------------

#include <ctype.h>
#include <math.h>
#include <stdio.h>

int htoi(char s[]);
int length(char s[]);

main()
{
    printf("%d\n", htoi("34"));        // 52
    printf("%d\n", htoi("-34"));       // -52
    printf("%d\n", htoi("0x34"));      // 52
    printf("%d\n", htoi("0X34"));      // 52
    printf("%d\n", htoi("2F"));        // 47
    printf("%d\n", htoi("0x12c9a"));   // 76954
    printf("%d\n", htoi("-0x12c9a"));  // -76954
    printf("%d\n", htoi("0x"));        // Print error message
    printf("%d\n", htoi("1g"));        // Print error message
}

// htoi: Converts a string of hexadecimal digits into its equivalent integer
// value.
int htoi(char s[])
{
    int i, min, len, n;
    char c, neg;

    // Specifies beginning of string. If string is negative or has preceding 
    // 0x or 0X characters, min is increased.
    min = 0;
    if (s[0] == '-') {
        neg = 1;
        min = 1;
    } else
        neg = 0;

    // Ignore optional 0x or 0X if it exists.
    len = length(s);
    if (len > 2 && s[min+0] == '0' && (s[min+1] == 'x' || s[min+1] == 'X'))
        min += 2;

    // Looping from right to left is more natural for this algorithm.
    n = 0;
    for (i = len-1; i >= min; --i) {
        c = s[i];
        if (!isdigit(c)) {
            // This conversion only works for the ASCII character set.
            // First, ensure that c is an uppercase letter.
            c = toupper(c);
            // Shift character 
            c = c - 'A' + 10;
            if (c > 15) {
                printf("Invalid hexadecimal number.\n");
                return 0;  // Not sure what is idiomatic. Must return int.
            }
        } else
            // Convert character to number. See comment in atoi.c for more.
            c = c - '0';
        n += c * pow(16, len-1-i);
    }
    
    if (neg)
        return 0-n;
    return n;
}

// length: Returns length of string.
int length(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
};
