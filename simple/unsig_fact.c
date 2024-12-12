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

