/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void demo(void){
    unsigned int x = 10 ;
    int y = -40;
    unsigned int z= x+y;
    if(z > 10) {
        printf("Greater than 10");
    } else {
        printf("Less than or equals 10");
    }
}

int main()
{
    demo();
    
    int num1=20, num2=30;
    num1^=num2^=num1^=num2;
    printf("\nnum1 : %d and num2 : %d\n", num1, num2);

    unsigned b;

    return 0;
}
