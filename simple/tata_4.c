/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// 12,11,8,10,5,3 sort using sorting



int main()
{
    int arr[] = {12, 11, 8, 10, 5, 3};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    

    return 0;
}