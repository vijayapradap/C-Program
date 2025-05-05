#include <stdio.h>

void selectionSort(int *arr, int size) {
    
    for(int i=0; i<size; i++) {
        int min = i;
        for(int j=i+1; j<size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(){
   int n;
   n = 5;
   int arr[5] = {12, 19, 55, 2, 16}; // initialize the array
   printf("Array before Sorting: ");
   for(int i = 0; i<n; i++)
      printf("%d ",arr[i]);
   printf("\n");
   selectionSort(arr, n);
   printf("Array after Sorting: ");
   for(int i = 0; i<n; i++)
      printf("%d ", arr[i]);
   printf("\n");
}
