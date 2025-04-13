#include <stdio.h>
#include <stdint.h>

uint32_t reverseHex(uint32_t num) {
    uint32_t reversed = 0;
    
    while (num > 0) {
        reversed = (reversed << 4) | (num & 0xF);
        num >>= 4;
    }
    
    return reversed;
}

int main() {
    uint32_t num = 0x12345678;
    uint32_t reversedNum = reverseHex(num);
    
    printf("Original: 0x%x\n", num);
    printf("Reversed: 0x%x\n", reversedNum);
    
    return 0;
}
