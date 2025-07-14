/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

char *reverseWord(char *input) {
    
    char *store[MAX] = {NULL}, *output = NULL;
    int i = 0;
    char *savePtr = NULL;
    
    char *temp = strdup(input);
    char *token = strtok_r(temp, " ", &savePtr);
    while(token != NULL) {
        store[i] = strdup(token);
        token = strtok_r(NULL, " ", &savePtr);
        i++;
    }
    store[i] = NULL;
    
    output = malloc(strlen(input));
    
    for(i; i >= 0; i--) {
        if (store[i] != NULL) {
            if (output == NULL)
                strcpy(output, store[i]);
            else 
                strcat(output, store[i]);
            strcat(output, " ");
            free(store[i]);
        }
    }
    free(temp);
    
    return output;
}

int main()
{
    char *data = "Quick Sort algorithm in various programming";
    
    printf("before reverse : %s\n", data);
    char *output = reverseWord(data);
    printf("after reverse : %s\n", output);
    
    free(output);
    return 0;
}