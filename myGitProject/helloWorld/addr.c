#include <stdio.h>
#include <stdint.h>

int main()
{
    int a = 10;
    uint32_t *p = (uint32_t *)0xa0050010;
#if 0 
    &p = &a;

    printf("addr : &a : %p\n",&a);
    printf("addr : &p : %p\n",&p);
    printf("addr : *p : %u\n",*p);
#endif

    for(int i=0; i<5; i++)
        printf("add %p \n", p++);

    return 0;
}
