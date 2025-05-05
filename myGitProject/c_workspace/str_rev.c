/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

// input: hello how are you
// output: Hello How Are You

int main()
{
    char *input = {"hello how are you"};
    char output[20];
    
    int i=0, j = 0;
    while(input[i] != '\0') {
        if (input[i] == ' ' || i == 0) {
            if (i > 0) {
                // printf(" ");
                output[i] = input[i];
                i++;
            }
            // printf("%c", (input[i] - 0x20));
            output[i] = (input[i] - 0x20);
        } else {
            // printf("%c", input[i]);
            output[i] = input[i];
        }
        i++;
    }
    
    printf("\noutput : %s\n", output);

    return 0;
}