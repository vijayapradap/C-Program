/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashItem;

HashItem* hashTable[TABLE_SIZE];

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = (HashItem*)malloc(sizeof(HashItem));
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

int search(int key) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key)
            return hashTable[index]->value;
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: ", i);
        HashItem* current = hashTable[i];
        if (current != NULL) {
            printf("%d -> ", current->key);
            // printf("%d -> ", current->value);
            // current = current->next;
        }
        printf("NULL\n");
    }
}

void twoSum(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = search(complement);
        if (index != -1) {
            printf("Indices: %d and %d\n\n", index, i);
            return;
        }
        insert(nums[i], i);
    }
    printf("No two sum solution found.\n\n");
}

int main() {
    int nums[] = {2, 12, 7, 11, 15};
    int target = 18;
    int size = sizeof(nums) / sizeof(nums[0]);

    twoSum(nums, size, target);
    
    display();

    return 0;
}