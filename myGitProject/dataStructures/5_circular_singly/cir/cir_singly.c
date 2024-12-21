#include <stdio.h>
#include <stdlib.h>

struct node {
	int a;
	struct node *next;
};

struct node *head;

void printVals(const char *func) {
	struct node *ptr;

	printf("calling \"%s\" function...\n", func);

	ptr = head;
	if (ptr == NULL) {
		printf("nothing has to print\n");
		return;
	} else {
		while(ptr->next != head) {
			printf("%d ",ptr->a);
			ptr = ptr->next;
		}
		printf("%d ", ptr->a);
	}
	printf("\n\n");
}

void begInsert(int val) {
	struct node *ptr, *temp;

	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("memory alloction is getting failed\n");
		return;
	}
	ptr->a = val;

	if (head == NULL) {
		head = ptr;
		ptr->next = head;
	} else {
		temp = head;
		while(temp->next != head) {
			temp = temp->next;
		}
		ptr->next = head;
		temp->next = ptr;
		head = ptr;
	}
	printVals(__func__);
}

void lastInsert(int val) {
	struct node *ptr, *temp;

	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("memory alloction is getting failed\n");
		return;
	}
	ptr->a = val;

	if (head == NULL) {
		head = ptr;
		ptr->next = head;
	} else {
		temp = head;
		while(temp->next != head) {
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = head;
	}
	printVals(__func__);
}

void beginDelete() {
	struct node *temp;
	if (head == NULL) {
		printf("nothing to delete\n");
	} else if(head->next == head) {
		head = NULL;
		free(head);
		printf("1 node was there and removed\n");
	} else {
		temp = head;
		while(temp->next != head) {
			temp = temp->next;
		}
		temp->next = head->next;
		free(head);
		head = temp->next;
	}
	printVals(__func__);
}

void lastDelete() {
	struct node *temp, *ptr;
	if (head == NULL) {
		printf("nothing to delete\n");
	} else if(head->next == head) {
		head = NULL;
		free(head);
		printf("1 node was there and removed\n");
	} else {
		temp = head;
		while(temp->next != head) {
			ptr = temp;
			temp = temp->next;
		}
		ptr->next = temp->next;
		free(temp);
	}
	printVals(__func__);
}

void search(int val) {
	struct node *ptr;
	int i = 0;

	ptr = head;
	while(ptr->next != head) {
		printf("val : %d\n", ptr->a);
		if (ptr->a == val) {
			printf("available in %dth node : %d\n",i, ptr->a);
			return;
		}
		i++;
		ptr = ptr->next;
	}
	if (ptr->a == val) {
		printf("available in %dth node : %d\n",i, ptr->a);
		return;
	}

	printf("%d values isn't availble in node\n", val);
}

void main() {
	begInsert(20);
	begInsert(10);

	lastInsert(30);
	lastInsert(40);

	beginDelete();

	lastDelete();
	lastInsert(10);
	search(10);
}
