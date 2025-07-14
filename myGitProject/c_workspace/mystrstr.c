/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

char *mystrstr(char *string, char *substring) {
    
    int i = 0;
    
    while(string[i] != '\0') {
        if (!strncmp((string + i), substring, strlen(substring))) {
            return (string + i);
        }
        i++;
    }
    
    return NULL;
}

int main()
{
    printf("output : %s\n", mystrstr("GDB online is an online compiler and debugger tool", "online d"));

    return 0;
}