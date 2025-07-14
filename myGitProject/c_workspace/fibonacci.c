/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void febFunc(int start, int end) {
    int first = 0, second = 1, output = 0;
    
    for(int i = 0; i <= end; i++) {
        if (i <= 1) {
            output = i;
        } else {
            output = first + second;
            first = second;
            second = output;
        }
        
        if (start <= output && output <= end)
            printf("%d ", output);
    }
}

int main()
{
    febFunc(0, 100);

    return 0;
}
