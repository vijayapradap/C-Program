/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char *mystrstr(char *string, char *substring) {
    
    int i = 0;
    
    while(string[i++] != '\0') {
        int j = 0;
        for(int x = i; substring[j] != '\0'; x++, j++) {
            if (string[x] != substring[j])
                break;
        }
        if (substring[j] == '\0')
            return (string + i);
    }
    
    return NULL;
}

int main()
{
    printf("output : %s\n", mystrstr("GDB online is an online compiler online coding and debugger tool", "online cod"));

    return 0;
}