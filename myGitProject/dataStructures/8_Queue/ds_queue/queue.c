#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct node {
    int a;
    struct node *next;
};

typedef struct node node;

node *front = NULL;
node *rear = NULL;

void display(void) {
    node *ptr = NULL;
    ptr = front;

    if (ptr == NULL) {
        printf("database is empty\n");
        return;
    }

    printf("database : \n");
    while(ptr != NULL) {
        printf("%d ",ptr->a);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(int data) {
    node *ptr = NULL;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("malloc() memory allocation failed\n");
        return;
    }
    ptr->a = data;
    ptr->next = NULL;

    if (front == NULL) {
        front = ptr;
        rear = ptr;
        front->next = NULL;
        rear->next = NULL;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
}

void delete(void) {
    node *ptr = NULL;
    if (front == NULL) {
        printf("database is empty\n");
    } else {
        ptr = front->next;
        free(front);
        front = ptr;
    }
}

void main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    delete();
    display();

    free(front);
    free(rear);
}