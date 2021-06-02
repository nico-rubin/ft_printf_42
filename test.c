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

    // d and i
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

    printf("\n\nWIDTH AND FLAGS\n\n"); // WIDTH and FLAGS
    printf("%10d\n", 5); // In no case does a non-existant or small field width cause truncation of a field.

    printf("%*d\n", 10, 5); // A field width may be '*' instead of a digit string in which case an argument supplies the width.

    // 0
    printf("%010d\n", 5); // A leading '0' functions like the width field with the ' 's replaced by '0'.

    printf("%0*d\n", 10, 5); // A field width may be '*' instead of a digit string in which case an argument supplies the width.

    // -
    printf("%-10d\n", 5); // The '-' flag functions in conjunction with the width field, left aligns the result.

    printf("%-010d\n", 5); // Flag '0' is ignored when flag '-' is present.

    printf("%0-10d\n", 5); // Flag '0' is ingored when flag '-' is present.

    // .

    printf("%.3s\n", "Hello there"); // For strings the '.' specifies the maximum limit on the output.

    printf("%.s\n", "Hello there"); // For strings if the digit string is missing the precision is treated as 0.

    printf ("%.*s\n", 3, "Hello there"); // A precision may be '*' instead of a digit string in which case an argument supplies the width.

    printf("Hello there %.*s Nico\n", "Top Gun"); // If the precision is given by '*' but the argument is not an int then the string is NULL.

    printf("%010.3s\n", "Hello"); // The '0' flag results in undefined behaviour with 's' conversion specifiers.

    printf("%.100s\n", "Hello"); // If the padding

    printf("%.30d\n", 10); // For integers, the precision controls the minimum of numbers printed, padding with '0'.

    printf("%.0d", 0); // If '.0' is specified, the number 0 will have no output.
}

