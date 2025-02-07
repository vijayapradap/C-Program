/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// 0x12345678
// 0x82345671

#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t input = 0x12345678;
    
    // uint32_t output = ((input & 0xf) << 28) | ((input & 0xfffffff0) >> 28);
    // printf("out : %x\n", (output | (input & 0x0ffffff0)));
    
    // or
    
    uint32_t output = ((input & 0xf) << 28) | ((input & 0xfffffff0) >> 28) | (input & 0x0ffffff0);
    printf("out : 0x%x\n", output);
    
    return 0;
}