#include <stdio.h>
// void insertionSort(int array[], int size){
//   int key, j;
//   for(int i = 1; i<size; i++) {
//       key = array[i];//take value
//       j = i;
//       while(j > 0 && array[j-1]>key) {
//          array[j] = array[j-1];
//          j--;
//       }
//       array[j] = key; //insert in right place
//   }
// }

void insertionSort(int array[], int size) {

    for(int i=1; i<size; i++) {
        int key = array[i];
        int j = i;
        while(j > 0 && key < array[j-1]) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;
    }
}

int main(){
    int n;
    n = 5;
    int arr[5] = {67, 44, 82, 17, 20}; // initialize the array
    printf("Array before Sorting: ");
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
    insertionSort(arr, n);
    printf("Array after Sorting: ");
    for(int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
