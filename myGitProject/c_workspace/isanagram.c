/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/



// isAnagram(String left, String right) -> returns true or false

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 256

bool isAnagram(char *left, char *right) {
    bool success = true;
    int num[SIZE] = {0};
    
    if(strlen(left) != strlen(right))
        return false;
    
    for(int i=0; left[i] != '\0'; i++) {
        num[left[i]]++;
        num[right[i]]--;
    }
    
    for(int i=0; i<SIZE; i++) {
        if (num[i] != 0)
            success = false;
    }
    
    return success;
}

int main () {
    char *left = "DOG";
    char *right = "KOD";
    
    if (isAnagram(left, right) == true) {
        printf("yes, it's anagram");
    } else {
        printf("yes, it's not anagram");
    }
}