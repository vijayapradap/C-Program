#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_MAX_SIZE 10

struct cirNode {
    uint8_t buffer[BUFFER_MAX_SIZE];
    int8_t front;
    int8_t rear;
};

typedef struct cirNode cirNode;
cirNode cirBuffer = { "\0", -1, -1 };

void enqueue(uint8_t data) {
    if (cirBuffer.front == -1 && cirBuffer.rear == -1) {
        cirBuffer.front = 0;
        cirBuffer.rear = 0;
        cirBuffer.buffer[cirBuffer.rear] = data;
    } else if (((cirBuffer.rear + 1) % BUFFER_MAX_SIZE) == cirBuffer.front) {
        printf("Buffer Overflow\n");
        return;
    } else {
        cirBuffer.rear = (cirBuffer.rear + 1) % BUFFER_MAX_SIZE;
        cirBuffer.buffer[cirBuffer.rear] = data;
    }
    printf("data %d added successfully in location %d\n",data, cirBuffer.rear);
}

int8_t dequeue(uint8_t *data) {
    if (cirBuffer.front == -1 && cirBuffer.rear == -1) {
        printf("Buffer Underflow\n");
        return -1;
    } else if (cirBuffer.front == cirBuffer.rear) {
        *data = cirBuffer.buffer[cirBuffer.front];
        cirBuffer.front = -1;
        cirBuffer.rear = -1;
    } else {
        *data = cirBuffer.buffer[cirBuffer.front];
        cirBuffer.front = (cirBuffer.front + 1) % BUFFER_MAX_SIZE;
    }
    return 0;
}

void display(void) {

    int front = cirBuffer.front;

    printf("output : %d ", cirBuffer.buffer[front]);
    while(front != cirBuffer.rear) {
        front=(front+1)%BUFFER_MAX_SIZE;
        printf("%d ", cirBuffer.buffer[front]);
    }
    printf("\n");
}

void main(void) {

    uint8_t data = 0;
    for(int i=0; i<BUFFER_MAX_SIZE; i++) {
        enqueue(i);
    }
    for(int i=0; i<4; i++) {
        if (dequeue(&data) == 0) {
            printf("dequeue output is : %d\n", data);
        }
    }

    for(int i=0, j=20; i<BUFFER_MAX_SIZE; i++, j++) {
        enqueue(j);
    }

    display();
}