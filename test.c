#include <stdio.h>

int main(void)
{
    // FORMAT

    // c
    printf("%c\n", 'c');

    // s
    printf("%s\n", "Hello");

    // p
    int p = 0;
    printf("%p\n", &p);

    // d
    printf("%d\n", 100);

    // i
    printf("%i\n", 100);

    // u
    printf("%u\n", 100);

    // x
    printf("%x\n", 42069);

    // X
    printf("%X\n", 42069);

    // %
    printf("%%\n");

    // WIDTH and FLAGS
    printf("%10d\n", 5); // The width is the minimum number of characters to output. 

    printf("%*d\n", 10, 5); // A field width may be '*' instead of a digit string in which case an argument supplies the width.

    // 0
    printf("%010d\n", 5); // A leading '0' functions like the width field with the ' 's replaced by '0'.

    printf("%0*d\n", 10, 5); // A field widht may be '*' instead of a digit string in which case an argument supplies the width.

    // -
    printf("%-10d\n", 5); // The '-' flag functions in conjunction with the width field, left aligning the result.

    printf("%-010d\n", 5); // Flag '0' is ignored when flag '-' is present.
    
    // .
    printf("%.3s\n", "Hello there"); // The '.' specifies the maximum limit on the output.

    printf("%.s\n", "Hello there"); // If the digit string is missing the precision is treated as 0.

    printf ("%.*s\n", 3, "Hello there"); // A precision may be '*' instead of a digit string in which case an argument supplies the width.
}