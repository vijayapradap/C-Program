#include <stdio.h>
#include <stdint.h>

#define SIZE(a) (a>16) ? 31 : (a>8) ? 15 : 7

void dec_to_bin(uint32_t a) {
    int bin[32], i = 0;
    while(a > 0) {
        bin[i] = a % 2;
        a = a / 2;
        i++;
    }
    
    for(int j=SIZE(i); j>=0; j--) {
        printf("%d ", bin[j]);
    }
}

int main()
{
    dec_to_bin(0xff00);
    return 0;
}
