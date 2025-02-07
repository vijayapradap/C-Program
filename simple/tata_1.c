/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// input: 5->10->8->5->9->3
// output:5->9->8->5->10->3

#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node *next;
};

struct node *head = NULL;

void display(void) {
    struct node *temp = NULL;
    temp = head;
    
    printf("output : ");
    while(temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n\n");
}


void addBegin(int value) {
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("malloc() memory allocation failed\n");
        return;
    }
    temp->a = value;
    if(head == NULL) {
        temp->next = NULL;
    } else {
        temp->next =  head;
    }
    head = temp;
}

void swapValue(int a, int b) {
    struct node *temp = NULL;
    
    temp = head;
    
    while(temp != NULL) {
        if (a == temp->a) {
            temp->a = b;
        } else if (b == temp->a) {
            temp->a = a;
        }
        temp = temp->next;
    }
}


int main()
{
    int arr[] = {5,10,8,5,9,3};
    
    for(int i=5; i>=0; i--) {
        addBegin(arr[i]);
    }
    
    display();
    
    swapValue(9, 10);
    
    display();
    
    free(head);

    return 0;
}