#include <stdio.h>
#include <stdlib.h>

struct node {
	int a;
	struct node *next;
};

struct node *head;

char *preFunc = NULL;
static void printFunc(const char *val) {
	if (preFunc != val) {
		printf("\nCalling \"%s\" function\n", val);
		preFunc = (char *)val;
	}
}

void printVals();

void beginsert(int val) {

	printFunc(__func__);
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL) {
		printf("memory allocation getting failed\n");
		return;
	}
	temp->a = val;
	temp->next = head;

	head = temp;
	printVals();
}

void lastinsert(int val) {
	printFunc(__func__);
	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL) {
		printf("memory allocation getting failed\n");
		return;
	}
	temp->a = val;
	if (head == NULL) {
		temp->next=NULL;
		head = temp;
	} else {
		ptr = head;
		while(ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->next = NULL;
	}
	printVals();
}

void deleteFirstNode() {
	printFunc(__func__);
	struct node *temp;
	temp = head;
	if (head == NULL) {
		printf("node is empty\n");
	} else {
		head = temp->next;
		free(temp);
	}
	printVals();
}

void deleteLastNode() {
	printFunc(__func__);
	struct node *temp, *ptr;
	if(head == NULL) {
		printf("node is empty\n");
	} else if (head->next == NULL) {
		free(head);
		printf("only one node was there and removed\n");
	} else {
		temp = head;
		while(temp->next != NULL) {
			ptr = temp;
			temp = ptr->next;
		}
		ptr->next = NULL;
		free(temp);
	}
	printVals();
}

void deleteNthNode(int val) {
	printFunc(__func__);
	struct node *temp, *ptr;
	if(head == NULL) {
		printf("node is empty\n");
	} else {
		val = val- 1;
		temp = head;
		for(int i=0; i<val; i++) {
			ptr = temp;
			temp = temp->next;
			if (temp == NULL) {
				printf("can't delete %d node\n",val);
				return;
			}
		}
		ptr->next = temp->next;
		free(temp);
	}
	printVals();
}

void insertNthNode(int loc, int val) {
	printFunc(__func__);
	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL) {
		printf("memory allocation getting failed\n");
		return;
	}
	temp->a = val;
	ptr = head;
	loc = loc - 1;
	for(int i=0; i<loc; i++) {
		ptr = ptr->next;
		if (ptr == NULL) {
			printf("provides location %d is't valid\n", loc);
			return;
		}
	}
	temp->next = ptr->next;
	ptr->next = temp;
	printVals();
}

void printVals() {
	struct node *temp;
	temp = head;

	if (temp == NULL) {
		printf("node is empty\n");
		return;
	} else {
		//printf("output after function call....\n");
		while(temp != NULL) {
			printf("%d ",temp->a);
			temp = temp->next;
		}
		printf("\n\n");
	}
}

void main() {
	int a[5] = { 10, 20, 30, 40, 50 };

	for(int i=0; i<5; i++)
		lastinsert(a[i]);
	
	lastinsert(60);

	beginsert(5);

	deleteFirstNode();

	deleteLastNode();

	deleteNthNode(2);
	
	insertNthNode(2, 100);
	
}
