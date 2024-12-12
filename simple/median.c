#include <stdio.h>

int main()
{
    int a = 55, b = 69, c = 40;
    
    if ( (a < b && b < c) || (a > b && b > c) ) {
        printf("b is median number\n");
    } else if ( (b < a && a < c) || (b > a && a > c)) {
        printf("a is median number\n");
    } else {
        printf("c is median number\n");
    }
    
    return 0;
}

