#include <stdio.h>  

int main( )  
{  
	int a = 5;  
	int *b;  
	int **c;  
	b = &a;  
	c = &b;  
	printf ("value of a\t = %d\n", a);  
	printf ("value of *(&a)\t = %d\n", *(&a));  
	printf ("value of *b\t = %d\n", *b);  
	printf ("value of **c\t = %d\n", **c);  
	printf ("value of b = address of a = %p\n", b);  
	printf ("value of c = address of b = %p\n", c);  
	printf ("address of &a\t = %p\n", &a);  
	printf ("address of b\t = %p\n", b);  
	printf ("address of *c\t = %p\n", *c);  
	printf ("address of &b\t = %p\n", &b);  
	printf ("address of c\t = %p\n", c);  
	printf ("address of &c\t = %p\n", &c);  
	return 0;  
}  
