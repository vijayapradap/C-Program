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
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void printVal(char const *func) {
    
    struct node *tmp = NULL;
    tmp = head;
    printf("\nfunc : %s\noutput : ", func);
    while(tmp != NULL) {
        printf("%d ", tmp->a);
        tmp = tmp->next;
    }
    printf("\n");
}

void addBegin(int a) {
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    tmp->a = a;
    tmp->prev = NULL;
    
    if (head == NULL) {
        tmp->next = NULL;
    } else {
        tmp->next = head;
        head->prev = NULL;
    }
    head = tmp;
    printVal(__func__);
}

void delBegin(void) {
    struct node *tmp = NULL;
    if (head == NULL) {
        printf("database is empty\n");
        return;
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("one database was there and removed\n");
        return;
    } else {
        tmp = head->next;
        free(head);
        head = NULL;
        head = tmp;
        head->prev = NULL;
    }
    printVal(__func__);
}

void addLast(int a) {
    struct node *tmp = NULL, *ptr = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    tmp->a = a;
    tmp->next = NULL;
    
    if (head == NULL) {
        tmp->prev = NULL;
        head = tmp;
    } else {
        ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        tmp->prev = ptr;
        ptr->next = tmp;
    }
    printVal(__func__);
}

void delLast(void) {
    struct node *tmp = NULL;
    if (head == NULL) {
        printf("database is empty\n");
        return;
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("one database was there and removed\n");
        return;
    } else {
        tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->prev->next = NULL;
        free(tmp);
        tmp = NULL;
    }
    printVal(__func__);
}

int main()
{
    addBegin(10);
    addBegin(20);
    delBegin();
    
    addLast(20);
    addLast(30);
    delLast();
    delLast();

    free(head);
    return 0;
}
