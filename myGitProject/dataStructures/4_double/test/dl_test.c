#include <stdio.h>
#include <stdlib.h>

struct node {
	int a;
	struct node *prev;
	struct node *next;
};

struct node *head;

void printVals(const char *msg) {
	struct node *ptr;
	ptr = head;

	if(ptr == NULL) {
		printf("node is empty\n");
		return;
	}
	
	printf("\nFunction \"%s\" \t: ", msg);

	while(ptr != NULL) {
		printf("%d ",ptr->a);
		ptr = ptr->next;
	}
	printf("\n\n");
}

void begInsert(int val) {

	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("memory allocation getting failed\n");
		return;
	}
	ptr->a = val;
	ptr->prev = NULL;
	if (head == NULL) {
		ptr->next = NULL;
		head = ptr;
	} else {
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
	printVals(__func__);
}

void lastInsert(int val) {
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("memory allocation getting failed\n");
		return;
	}
	ptr->a = val;
	ptr->next = NULL;
	if (head == NULL) {
		ptr->prev = NULL;
		head = ptr;
	} else {
		temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		ptr->prev = temp;
		temp->next = ptr;
	}
	printVals(__func__);
}

void deleteBegin() {
	struct node *ptr;

	ptr = head;

	if (ptr == NULL) {
		printf("node is empty");
		return;
	} else if (ptr->next == NULL) {
		head=NULL;
		free(head);
		printf("single not was deleted\n");
		return;
	}

	ptr->next->prev = NULL;
	head = ptr->next;

	free(ptr);
	printVals(__func__);
}
void deleteLast() {
	struct node *ptr;

	if (head == NULL) {
		printf("node is empty");
		return;
	} else if (head->next == NULL) {
		head = NULL;
		free(head);
		printf("single not was deleted\n");
		return;
	}

	ptr = head;
	while(ptr->next != NULL)
		ptr = ptr->next;

	ptr->prev->next = NULL;
	//head = ptr->prev;

	free(ptr);
	printVals(__func__);
}

void insertNthNode(int pos, int val) {
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("memory allocation getting failed\n");
		return;
	}
	ptr->a = val;
	temp = head;

	for(int i=0; i<pos; i++) {
		if (temp == NULL) {
			printf("can't insert the value given position\n");
			free(ptr);
			return;
		}
		temp = temp->next;
	}
	ptr->prev = temp;
	ptr->next = temp->next;
	temp->next = ptr;
	temp->next->prev = ptr;
	printVals(__func__);
}

#if 0
void deleteNthNode(int pos) {
	struct node *ptr, *temp;
	
	ptr = head;
	for(int i=0; i<pos; i++) {
		if (ptr == NULL) {
			printf("can't insert the value given position\n");
			free(ptr);
			return;
		}
		ptr = ptr->next;
	}
	
	temp = ptr;
	ptr->next = temp->next;
	ptr->next->prev = temp->prev;
	free(temp);
	
	printVals(__func__);
}
#endif

void main() {
	begInsert(10);
	lastInsert(20);

	deleteBegin();
	lastInsert(30);
	lastInsert(40);
	lastInsert(50);

	deleteLast();
	insertNthNode(2, 50);
}
