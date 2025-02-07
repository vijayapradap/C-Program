#include "stdio.h"

// Define a list of variables using X-macros
#define VARIABLES \
X(var1, 1) \
X(var2, 2) \
X(var3, 3) \
X(var4, 4) 
 
// Main program
int	 main (void) 
{ 
	// Declare each variable using a macro
#define X(name, number) char name[10];
	VARIABLES 
#undef X
	
	// Accept input for each variable
#define X(name, number) printf("Enter Name %d\n", number); \
                        scanf("%9s", name); 
	VARIABLES 
#undef X
	
	// Print the values
#define X(name, number) printf("%d) %s\n", number, name);
	VARIABLES 
#undef X
	
return 0;
	 
}


