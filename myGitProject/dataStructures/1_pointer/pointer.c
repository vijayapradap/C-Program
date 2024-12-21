#include <stdio.h>  

int main( )  
{  
	int a = 5;  
	int *b;  
	b = &a;  

	printf ("value of a = %d\n", a);  
	printf ("value of *(&a) = %d\n", *(&a));  
	printf ("value of *b = %d\n", *b);  
	printf ("address of &a = %p\n", &a);  
	printf ("address of b = %p\n", b);  
	printf ("address of &b = %p\n", &b);  
	printf ("value of b = address of a = %p\n\n", b);  
	return 0;  
}
