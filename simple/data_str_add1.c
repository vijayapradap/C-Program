/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
};

struct node *head = NULL;

void printData(void) {
    struct node *tmp = head;
    
    printf("output data : ");
    while(tmp != NULL) {
        printf("%d ",tmp->x);
        tmp = tmp->next;
    }
    printf("\n");
}

void addFront(int value) {
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("error allocating memory\n");
        return;
    }
    tmp->x = value;
    tmp->next = head;
    
    head = tmp;
    printData();
}

void addBack(int value) {
    struct node *tmp = NULL, *ptr = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("error allocating memory\n");
        return;
    }
    tmp->x = value;
    tmp->next = NULL;
    
    if (head == NULL) {
        head = tmp;
    } else {
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        
        ptr->next=tmp;
        // head = ptr;
    }
    printData();
}

int main()
{
    addFront(10);
    addBack(15);
    addFront(5);
    addFront(2);
    addBack(20);

    return 0;
}
