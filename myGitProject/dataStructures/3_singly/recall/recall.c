#include <stdio.h>
#include <stdlib.h>

struct node {
	int a;
	struct node *next;
};

struct node *head;

void printVals(const char *func) {
	printf("\ncalling \"%s\" and values : ", func);
	struct node *ptr;

	if (head == NULL) {
		printf("line : %d node is EMPTY\n\n", __LINE__);
	} else {
		ptr = head;
		while(ptr != NULL) {
			printf("%d ", ptr->a);
			ptr = ptr->next;
		}
	}
	printf("\n");
}

void insertFirst(int val) {
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("heap memory allocation failed : %d\n", __LINE__);
		return;
	}
	ptr->a = val;
	ptr->next = head;

	head = ptr;
	printVals(__func__);
}

void insertLast(int val) {
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("heap memory allocation failed : %d\n", __LINE__);
		return;
	}
	ptr->a = val;
	ptr->next = NULL;
	
	temp = head;
	if (temp->next == NULL) {
		temp->next = ptr;
	} else {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = ptr;
	}

	printVals(__func__);
}

void deleteFirst() {
	struct node *ptr;
	if(head == NULL) {
		printf("line : %d node is EMPTY\n", __LINE__);
		return;
	} else if(head->next == NULL) {
		printf("line : %d single node was there and removed\n", __LINE__);
		head = NULL;
		free(head);
	} else {
		ptr = head;
		head = ptr->next;
		free(ptr);
	}

	printVals(__func__);
}

void deleteLast() {
	struct node *ptr, *temp;
	if(head == NULL) {
		printf("line : %d node is EMPTY\n", __LINE__);
		return;
	} else if(head->next == NULL) {
		printf("line : %d single node was there and removed\n", __LINE__);
		head = NULL;
		free(head);
	} else {
		ptr = head;
		while(ptr->next != NULL) {
			temp = ptr;
			ptr = ptr->next;
		}
		temp->next = NULL;
		//head = temp;
		free(ptr);
	}

	printVals(__func__);
}

void main() {
	insertFirst(20);
	insertFirst(10);

	insertLast(30);
	insertLast(40);
	deleteFirst();
	deleteLast();
}
