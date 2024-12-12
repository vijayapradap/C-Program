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
