#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node {
    uint8_t data;
    struct node *next;
};

typedef struct node node;
node *front = NULL;
node *rear = NULL;

void enqueue(uint8_t val) {
    node *ptr = NULL;
    ptr = (node *)malloc(sizeof(node));
    if (ptr ==  NULL) {
        printf("malloc() size allocation getting failed\n");
        return;
    }
    ptr->data = val;
    ptr->next = 0;
    if (front == NULL && rear == NULL) {
        rear = front = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    rear->next = front;
}

void dequeue(void) {
    node *temp = front;
    if (front == NULL && rear == NULL) {
        printf("buffer Underflow");
    } else if (front == rear) {
        front = rear = NULL;
        free(temp);
    } else {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display(void) {
    node *temp = front;

    printf("output : %d ",temp->data);
    while(temp != rear) {
        temp = temp->next;
        printf("%d ",temp->data);
    }
    printf("\n");
}

void main(void) {
    for(int i=0; i<5; i++) {
        enqueue(11+i);
    }

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    enqueue(20);

    display();

    free(front);
    free(rear);
}