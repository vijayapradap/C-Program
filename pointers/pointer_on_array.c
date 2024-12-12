#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int (*ptr)[5] = &a;
    
    printf("single dimentional array : ");
    for(int i=0; i<5; i++)
        printf("%d ", (*ptr)[i]);
    printf("\n");

    int multi_arr[][4] = { {10, 19, 20, 12}, {30, 59, 32, 77} };
    int (*mptr)[4] = multi_arr;
    
    printf("single dimentional array : ");
    for(int i=0; i<8; i++)
        printf("%d ", (*mptr)[i]);
    printf("\n");
    
    // if we want to access the second row directly then,
    // mptr + 1 moves the pointer to the second row of the array.
    // *(mptr + 1) dereferences the pointer to get the address of the first element in the second row.
    // *(*(mptr + 1) + 0) dereferences this address to get the value 30.

    printf("step 1 : %u\n", mptr + 1);
    printf("step 2 : %u\n", *(mptr + 1));
    printf("step 3 : %u\n", *(*(mptr + 1)));

    int value = *(*(mptr + 1) + 2); // +2 is for accessing the coloums
    printf("value : %d\n", value);
    
    return 0;
}
