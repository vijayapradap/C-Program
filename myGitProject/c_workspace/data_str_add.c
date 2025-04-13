/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node *next;
};

struct node *head = NULL;

void addBegin( int data ) {
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    tmp->a = data;
    tmp->next = head;
    
    head = tmp;
}

void addLast( int data ) {
    struct node *tmp = NULL, *ptr = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    
    ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    
    tmp->a = data;
    tmp->next = NULL;
    
    ptr->next = tmp;
}

int main()
{
    int arr[] = {10, 20, 30};
    
    for(int i=0; i<3; i++)
        addBegin(arr[i]);
    
    addLast(40);
        
    while(head != NULL) {
        printf("%d ",head->a);
        head = head->next;
    }

    return 0;
}
