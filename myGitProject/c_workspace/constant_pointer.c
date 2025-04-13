/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    // pointer to char constant which is read only data
    
    const char *ptr;
    ptr = "vijayapradap M";
    
    printf("output : %s\n", ptr);
    
    char name[] = "vijay";
    
    // constant pointer to a char, pointer address won't change but data can
    char *const cptr = name;
    
    printf("output : %s\n", cptr);
    cptr[0] = 'V';
    printf("output : %s\n", cptr);

    return 0;
}