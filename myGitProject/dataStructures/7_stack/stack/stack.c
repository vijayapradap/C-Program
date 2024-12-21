#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10

int top = -1;

typedef struct node {
	int a;
	struct node *next;
} Node;

Node *head = NULL;

Node *memAlloc() {
	Node *ptr = NULL;
	ptr = (Node *)malloc(sizeof(Node));
	if (ptr == NULL) {
		printf("memory allocation getting failed in Line %d\n", __LINE__);
		return NULL;
	}
	return ptr;
}

void display(const char *func) {

	if (top == -1)
		return;
	
	printf("function \"%s\" invoked and output : ", func);

	if (head == NULL) {
		printf("nothing to print\n");
		return;
	} else {
		Node *ptr = head;
		while(ptr != NULL) {
			printf("%d ",ptr->a);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

bool isEmpty(void) {
	return (top == -1) ? true : false;
}

bool isFull(void) {
	return (top == (STACK_SIZE - 1)) ? true : false;
}

int count(void) {
	return (top + 1);
}

void push(int val) {

	if (isFull()) {
		printf("stack is already full\n");
		return;
	}

	Node *ptr = NULL;
	ptr = memAlloc();

	ptr->a = val;
	ptr->next = head;

	head = ptr;
	top += 1;
	display(__func__);
}

void pop() {

	if (isEmpty()) {
		printf("stack is empty\n");
		return;
	}

	Node *ptr = NULL;
	
	if (head == NULL) {
		printf("node is empty\n");
	} else if (head->next == NULL) {
		printf("single node was there and removed\n");
		free(head);
		head = NULL;
	} else {
		ptr = head->next;
		free(head);
		head = NULL;
		head = ptr;
	}
	top -= 1;
	display(__func__);
}

int main() {

	for(int i=0; i<=STACK_SIZE; i++)
		push(i+1 * 10);

	printf("output : %d\n",count());

	for(int i=0; i<=STACK_SIZE; i++)
		pop();

	free(head);
	return 0;
}
