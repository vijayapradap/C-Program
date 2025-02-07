/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

// 0xAB 0XBA using bitwise 

int main()
{
    uint8_t input = 0xAB, output = 0;
    
    printf("input : 0x%X\n", input);
    
    while(input != 0) {
        output = (output << 4) | (input & 0xF);
        input = input >> 4;
    }
    
    printf("Output : 0X%X\n", output);

    return 0;
}