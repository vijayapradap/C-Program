/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int reverse_num(int val)
{
    int rem = 0, rev = 0;
    
    while(val != 0) {
        rem = val % 10;
        rev = rev * 10 + rem;
        val = val / 10;
    }
    return rev;
}

int main()
{
    int value = 43456;
    printf("value before reverse : %d\n", value);
    printf("value after reverse : %d\n", reverse_num(value));

    return 0;
}
