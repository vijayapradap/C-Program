#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	struct node *next;
	int a;
};

struct node *head = NULL;

struct node *memAloc() {

	struct node *ptr = NULL;
	ptr = (struct node *)malloc(sizeof (struct node));
	if (ptr == NULL) {
		printf("memory allocation failed in line : %d\n", __LINE__);
		return NULL;
	}
	return ptr;
}

void display(const char *func) {
	printf("Invoked \"%s\" callback and values\t: ", func);
	struct node *ptr;

	ptr = head;
	if (head == NULL) {
		printf("node is empty\n");
		return;
	} else {
		while(ptr->next != head) {
			printf("%d ",ptr->a);
			ptr = ptr->next;
		}
		printf("%d\n",ptr->a);
	}
}

void insertBegin(int val) {
	struct node *ptr, *temp;

	ptr = memAloc();
	ptr->a = val;
	
	if (head == NULL) {
		head = ptr;
		ptr->prev = head;
		ptr->next = head;
	} else {
		temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = ptr;
		ptr->prev = temp;
		head->prev = ptr;
		ptr->next = head;
		head = ptr;
	}

	display(__func__);
}

void insertLast(int val) {
	struct node *ptr, *temp;
	ptr = memAloc();
	ptr->a = val;

	if (head == NULL) {
		head = ptr;
		ptr->prev = head;
		ptr->next = head;
	} else {
		temp = head;
		while(temp->next != head) {
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->prev = temp;
		head->prev = ptr;
		ptr->next = head;
	}
	display(__func__);
}

int main(void) {
	insertBegin(10);
	insertBegin(5);

	insertLast(20);
	return 0;
}
